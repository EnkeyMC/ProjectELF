//
// Created by MOmac on 23.03.2019.
//

#include "ELFSectionHeader.h"
#include "ELF.h"

namespace elf {

ELFSectionHeader::ELFSectionHeader(ELF &elf)
    : ELFStructureBase(elf), section_data(nullptr),
    index(0), header_valid(false), section_valid(false)
{

}

char *ELFSectionHeader::get_section_data() const {
    return section_data;
}

unsigned int ELFSectionHeader::get_index() const {
    return index;
}

void ELFSectionHeader::set_index(unsigned int index) {
    ELFSectionHeader::index = index;
}

bool ELFSectionHeader::is_header_valid() const {
    return header_valid;
}

void ELFSectionHeader::set_header_valid(bool valid) {
    header_valid = valid;
}

bool ELFSectionHeader::is_section_valid() const {
    return section_valid;
}

void ELFSectionHeader::set_section_valid(bool valid) {
    section_valid = valid;
}

void ELFSectionHeader::set_section_ptr(char *ptr) {
    this->section_data = ptr;
}

}
