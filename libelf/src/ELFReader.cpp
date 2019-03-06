//
// Created by MOmac on 02.03.2019.
//

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

}  // namespace elf
