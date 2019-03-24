//
// Created by MOmac on 02.03.2019.
//

#include <assert.h>
#include <ELFReader.h>

#include "ELFTypes.h"
#include "ELFReader.h"
#include "ELFHeaderImpl.h"
#include "ELFSectionHeaderImpl.h"

namespace elf {

ELFReader::ELFReader(std::istream &istream, elf::ELF &output) : istream(istream), elf(output) {
    auto stream_beginning = istream.tellg();
    istream.seekg(0, std::istream::end);
    elf.set_file_size(istream.tellg() - stream_beginning);
    istream.seekg(stream_beginning);
}

ELFIssuesBySeverity ELFReader::parse_header() {
    ELFIssuesBySeverity issues;

    this->elf.clear();

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

    for (int i = 0; i < shnum; ++i) {
        istream.seekg(shoff + shentsize * i);
        section_header = create_section_header();
        issues += parse_raw(*section_header, ISRC_SECTIONS_HEADER);
        elf.add_section_header(section_header);
    }

    return issues;
}

ELFIssuesBySeverity ELFReader::parse_program_headers() {
    return ELFIssuesBySeverity();
}

ELFIssuesBySeverity ELFReader::parse_sections() {
    return ELFIssuesBySeverity();
}

ELFIssuesBySeverity ELFReader::parse_segments() {
    return ELFIssuesBySeverity();
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

ELFIssuesBySeverity ELFReader::parse_raw(IRawParsable &parsable, ELFIssueSource issueSource) {
    ELFIssuesBySeverity issues;
    istream.read(parsable.get_bytes(), parsable.get_size());
    if (istream.gcount() != parsable.get_size())
        issues += ELFIssue(ISEV_CRITICAL, issueSource, ITYPE_UNEXPECTED_EOF);

    return issues;
}

}  // namespace elf
