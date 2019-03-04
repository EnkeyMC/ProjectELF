//
// Created by MOmac on 02.03.2019.
//

#include "ELFReader.h"

elf::ELFReader::ELFReader(std::istream &istream, elf::ELF &output) : istream(istream), elf(output) {

}

vector<ELFIssue> elf::ELFReader::parse_header() {
    return vector<ELFIssue>();
}

vector<ELFIssue> elf::ELFReader::parse_section_headers() {
    return vector<ELFIssue>();
}

vector<ELFIssue> elf::ELFReader::parse_program_headers() {
    return vector<ELFIssue>();
}

vector<ELFIssue> elf::ELFReader::parse_sections() {
    return vector<ELFIssue>();
}

vector<ELFIssue> elf::ELFReader::parse_segments() {
    return vector<ELFIssue>();
}
