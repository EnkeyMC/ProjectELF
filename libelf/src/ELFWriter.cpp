//
// Created by MOmac on 02.03.2019.
//

#include "ELFWriter.h"

namespace elf {

bool ELFWriter::save(const elf::ELF &elf, std::ostream &ostream) {
    bool is_good = save_segments(elf, ostream);
    is_good = is_good && save_sections(elf, ostream);
    is_good = is_good && save_header(elf, ostream);
    return is_good;
}

bool ELFWriter::save_sections(const ELF &elf, std::ostream &ostream) {
    bool is_good = true;
    auto shoff = elf.header->get_e_shoff();
    auto shentsize = elf.header->get_e_shentsize();

    for (auto section : elf.section_headers) {
        is_good = is_good && save_section(section, ostream);
        is_good = is_good && save_section_header(section, shoff + shentsize*section->get_index(), ostream);
    }

    return is_good;
}

bool ELFWriter::save_header(const ELF &elf, std::ostream &ostream) {
    ostream.seekp(0);
    ostream.write(reinterpret_cast<const char*>(elf.get_e_ident()), EI_NIDENT);
    ostream.write(elf.header->get_bytes(), elf.header->get_size());
    return ostream.good();
}

bool ELFWriter::save_section_header(ELFSectionHeader *section_header, std::streampos offset, std::ostream &ostream) {
    ostream.seekp(offset);
    ostream.write(section_header->get_bytes(), section_header->get_size());
    return ostream.good();
}

bool ELFWriter::save_section(ELFSectionHeader *section_header, std::ostream &ostream) {
    ostream.seekp(section_header->get_sh_offset());
    ostream.write(section_header->get_section_data(), section_header->get_sh_size());
    return ostream.good();
}

bool ELFWriter::save_segments(const ELF &elf, std::ostream &ostream) {
    bool is_good = true;
    auto phoff = elf.header->get_e_phoff();
    auto phentsize = elf.header->get_e_phentsize();

    for (auto program_header : elf.program_headers) {
        is_good = is_good && save_segment(program_header, ostream);
        is_good = is_good && save_program_header(program_header, phoff + phentsize*program_header->get_index(), ostream);
    }

    return is_good;
}

bool ELFWriter::save_program_header(ELFProgramHeader *program_header, std::streampos offset, std::ostream &ostream) {
    ostream.seekp(offset);
    ostream.write(program_header->get_bytes(), program_header->get_size());
    return ostream.good();
}

bool ELFWriter::save_segment(ELFProgramHeader *program_header, std::ostream &ostream) {
    ostream.seekp(program_header->get_p_offset());
    ostream.write(program_header->get_segment_data(), program_header->get_p_filesz());
    return ostream.good();
}

}
