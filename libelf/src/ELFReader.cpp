//
// Created by MOmac on 02.03.2019.
//

#include <cassert>
#include <iostream>

#include "ELFReader.h"
#include "ELFHeaderImpl.h"
#include "ELFSectionHeaderImpl.h"
#include "ELFProgramHeaderImpl.h"
#include "ELFIssueException.h"

namespace elf {

ELFReader::ELFReader(std::istream &istream, elf::ELF &output) : istream(istream), elf(output) {
    istream.seekg(0, std::istream::end);
    elf.set_file_size(static_cast<size_t>(istream.tellg()));
    istream.seekg(0);
}

void ELFReader::parse_header() {
    this->elf.clear();
    this->istream.seekg(0);

    unsigned char e_ident[EI_NIDENT];

    this->istream.read(reinterpret_cast<char *>(&e_ident), sizeof(e_ident));

    if (this->istream.gcount() != sizeof(e_ident)) {
        throw ELFIssueException(ELFIssue(ISEV_CRITICAL, ISRC_HEADER, ITYPE_UNEXPECTED_EOF));
    }

    this->elf.set_e_ident(e_ident);

    this->elf.header = create_header(e_ident[EI_CLASS]);

    auto header_parse_issue = this->parse_raw(*this->elf.header, ISRC_HEADER);
    if (header_parse_issue != ELFIssue::NO_ISSUE)
        throw ELFIssueException(header_parse_issue);
}

void ELFReader::parse_section_headers() {
    assert(elf.header != nullptr);

    Elf64_Off shoff = elf.header->get_e_shoff();
    Elf_Half shentsize = elf.header->get_e_shentsize();
    Elf_Half shnum = elf.header->get_e_shnum();
    ELFSectionHeader *section_header;

    for (unsigned int i = 0; i < shnum; ++i) {
        istream.seekg(shoff + shentsize * i);
        section_header = create_section_header();
        parse_raw(*section_header, ISRC_SECTIONS_HEADER, i);
        elf.add_section_header(section_header);
    }
}

void ELFReader::parse_program_headers() {
    assert(elf.header != nullptr);

    Elf64_Off phoff = elf.header->get_e_phoff();
    Elf_Half phentsize = elf.header->get_e_phentsize();
    Elf_Half phnum = elf.header->get_e_phnum();
    ELFProgramHeader *program_header;

    for (unsigned int i = 0; i < phnum; ++i) {
        istream.seekg(phoff + phentsize * i);
        program_header = create_program_header();
        parse_raw(*program_header, ISRC_PROGRAM_HEADER, i);
        elf.add_program_header(program_header);
    }
}

void ELFReader::parse_sections() {
    assert(this->elf.header != nullptr);

    for (auto section_header : elf.section_headers) {
        istream.seekg(section_header->get_sh_offset());

        char *buffer = new char[section_header->get_sh_size()];
        istream.read(buffer, section_header->get_sh_size());
        section_header->set_copy_of_section_data(buffer, section_header->get_sh_size());
    }
}

void ELFReader::parse_segments() {
    assert(this->elf.header != nullptr);

    for (auto program_header : elf.program_headers) {
        istream.seekg(program_header->get_p_offset());

        char *buffer = new char[program_header->get_p_filesz()];
        istream.read(buffer, program_header->get_p_filesz());
        program_header->set_segment_data(buffer, program_header->get_p_filesz());
    }
}

ELFHeader* ELFReader::create_header(unsigned char ei_class) const {
    if (ei_class == ELFCLASS32)
        return new ELFHeaderImpl<Elf32_Ehdr>(elf);
    else
        return new ELFHeaderImpl<Elf64_Ehdr>(elf);
}

ELFSectionHeader* ELFReader::create_section_header() const {
    if (elf.get_ei_class() == ELFCLASS32)
        return new ELFSectionHeaderImpl<Elf32_Shdr>(elf);
    else
        return new ELFSectionHeaderImpl<Elf64_Shdr>(elf);
}

ELFProgramHeader* ELFReader::create_program_header() const {
    if (elf.get_ei_class() == ELFCLASS32)
        return new ELFProgramHeaderImpl<Elf32_Phdr>(elf);
    else
        return new ELFProgramHeaderImpl<Elf64_Phdr>(elf);
}

ELFIssue ELFReader::parse_raw(IRawParsable &parsable, ELFIssueSource issue_source, unsigned issue_index) {
    std::fill_n(parsable.get_bytes(), parsable.get_size(), '\0');
    istream.read(parsable.get_bytes(), parsable.get_size());
    if (istream.gcount() != parsable.get_size())
        return {ISEV_CRITICAL, issue_source, ITYPE_UNEXPECTED_EOF, issue_index};
    return ELFIssue::NO_ISSUE;
}

void ELFReader::parse() {
    parse_header();
    parse_section_headers();
    parse_program_headers();
    parse_sections();
    parse_segments();
}

}  // namespace elf
