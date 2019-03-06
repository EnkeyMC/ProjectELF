//
// Created by MOmac on 02.03.2019.
//

#include "ELFTypes.h"
#include "ELFReader.h"

namespace elf {

ELFReader::ELFReader(std::istream &istream, elf::ELF &output) : istream(istream), elf(output) {

}

vector<ELFIssue> ELFReader::parse_header() {
    vector<ELFIssue> issues;

    this->elf.clear();

    unsigned char e_ident[EI_NIDENT];

    this->istream.read(reinterpret_cast<char *>(&e_ident), sizeof(e_ident));

    if (this->istream.gcount() != sizeof(e_ident)) {
        issues.emplace_back(ISEV_CRITICAL, ISRC_HEADER, ITYPE_UNEXPECTED_EOF);
        return issues;
    }



    return issues;
}

vector<ELFIssue> ELFReader::parse_section_headers() {
    return vector<ELFIssue>();
}

vector<ELFIssue> ELFReader::parse_program_headers() {
    return vector<ELFIssue>();
}

vector<ELFIssue> ELFReader::parse_sections() {
    return vector<ELFIssue>();
}

vector<ELFIssue> ELFReader::parse_segments() {
    return vector<ELFIssue>();
}

}  // namespace elf
