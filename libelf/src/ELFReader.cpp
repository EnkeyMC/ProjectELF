//
// Created by MOmac on 02.03.2019.
//

#include <cassert>
#include <ELFReader.h>
#include <iostream>

#include "ELFHeaderImpl.h"
#include "ELFSectionHeaderImpl.h"
#include "ELFProgramHeaderImpl.h"

namespace elf {

ELFReader::ELFReader(std::istream &istream, elf::ELF &output) : istream(istream), elf(output) {
    istream.seekg(0, std::istream::end);
    elf.set_file_size(static_cast<size_t>(istream.tellg()));
    istream.seekg(0);
}

ELFIssuesBySeverity ELFReader::parse_header() {
    ELFIssuesBySeverity issues;

    this->elf.clear();
    this->istream.seekg(0);

    unsigned char e_ident[EI_NIDENT];

    this->istream.read(reinterpret_cast<char *>(&e_ident), sizeof(e_ident));

    if (this->istream.gcount() != sizeof(e_ident)) {
        issues += ELFIssue(ISEV_CRITICAL, ISRC_HEADER, ITYPE_UNEXPECTED_EOF);
        return issues;
    }

    issues += this->elf.set_e_ident(e_ident);
    if (issues.has_critical_issue())
        return issues;

    this->elf.header = create_header(e_ident[EI_CLASS]);

    issues += this->parse_raw(*this->elf.header, ISRC_HEADER);
    issues += this->elf.header->find_issues();

    return issues;
}

ELFIssuesBySeverity ELFReader::parse_section_headers() {
    assert(elf.header != nullptr);
    
    ELFIssuesBySeverity issues{};
    Elf64_Off shoff = elf.header->get_e_shoff();
    Elf_Half shentsize = elf.header->get_e_shentsize();
    Elf_Half shnum = elf.header->get_e_shnum();
    ELFSectionHeader *section_header;

    for (unsigned int i = 0; i < shnum; ++i) {
        istream.seekg(shoff + shentsize * i);
        section_header = create_section_header();
        issues += parse_raw(*section_header, ISRC_SECTIONS_HEADER, i);
        elf.add_section_header(section_header);
    }

    return issues;
}

ELFIssuesBySeverity ELFReader::parse_program_headers() {
    assert(elf.header != nullptr);

    ELFIssuesBySeverity issues{};
    Elf64_Off phoff = elf.header->get_e_phoff();
    Elf_Half phentsize = elf.header->get_e_phentsize();
    Elf_Half phnum = elf.header->get_e_phnum();
    ELFProgramHeader *program_header;

    for (unsigned int i = 0; i < phnum; ++i) {
        istream.seekg(phoff + phentsize * i);
        program_header = create_program_header();
        issues += parse_raw(*program_header, ISRC_PROGRAM_HEADER, i);
        elf.add_program_header(program_header);
    }

    return issues;
}

ELFIssuesBySeverity ELFReader::parse_sections() {
    assert(this->elf.header != nullptr);
    ELFIssuesBySeverity issues{};

    for (auto section_header : elf.section_headers) {
        istream.seekg(section_header->get_sh_offset());

        char *buffer = new char[section_header->get_sh_size()];
        istream.read(buffer, section_header->get_sh_size());
        section_header->set_copy_of_section_data(buffer, section_header->get_sh_size());
    }

    return issues;
}

ELFIssuesBySeverity ELFReader::parse_segments() {
    assert(this->elf.header != nullptr);
    ELFIssuesBySeverity issues{};

    for (auto program_header : elf.program_headers) {
        istream.seekg(program_header->get_p_offset());

        char *buffer = new char[program_header->get_p_filesz()];
        istream.read(buffer, program_header->get_p_filesz());
        program_header->set_segment_data(buffer, program_header->get_p_filesz());
    }

    return issues;
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

ELFIssuesBySeverity ELFReader::parse_raw(IRawParsable &parsable, ELFIssueSource issue_source, unsigned issue_index) {
    ELFIssuesBySeverity issues;

    std::fill_n(parsable.get_bytes(), parsable.get_size(), '\0');
    istream.read(parsable.get_bytes(), parsable.get_size());
    if (istream.gcount() != parsable.get_size())
        issues += ELFIssue(ISEV_CRITICAL, issue_source, ITYPE_UNEXPECTED_EOF, issue_index);

    return issues;
}

}  // namespace elf
