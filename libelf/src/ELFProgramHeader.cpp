//
// Created by MOmac on 30.03.2019.
//

#include "ELFProgramHeader.h"

elf::ELFProgramHeader::ELFProgramHeader(elf::ELF &elf)
    : ELFStructureBase(elf), segment_data(nullptr),
    header_valid(false), segment_valid(false), index(0)
{}

char *elf::ELFProgramHeader::get_segment_data() const {
    return segment_data;
}

unsigned int elf::ELFProgramHeader::get_index() const {
    return index;
}

void elf::ELFProgramHeader::set_index(unsigned int index) {
    ELFProgramHeader::index = index;
}

bool elf::ELFProgramHeader::is_header_valid() const {
    return header_valid;
}

bool elf::ELFProgramHeader::is_segment_valid() const {
    return segment_valid;
}

void elf::ELFProgramHeader::set_header_valid(bool valid) {
    this->header_valid = valid;
}

void elf::ELFProgramHeader::set_segment_valid(bool valid) {
    this->segment_valid = valid;
}

void elf::ELFProgramHeader::set_segment_ptr(char *ptr) {
    this->segment_data = ptr;
}
