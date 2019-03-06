//
// Created by MOmac on 02.03.2019.
//

#include <ELFHeaderImpl.h>
#include "ELFTypes.h"
#include "ELFReader.h"

namespace elf {

ELFReader::ELFReader(std::istream &istream, elf::ELF &output) : istream(istream), elf(output) {

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
    issues += this->elf.header->load_from_stream(this->istream);
    issues += this->elf.header->find_issues();

    return issues;
}

ELFIssuesBySeverity ELFReader::parse_section_headers() {
    return ELFIssuesBySeverity();
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
        return new ELFHeaderImpl<Elf32_Ehdr>(elf, elf.get_converter());
    else
        return new ELFHeaderImpl<Elf64_Ehdr>(elf, elf.get_converter());
}

}  // namespace elf
