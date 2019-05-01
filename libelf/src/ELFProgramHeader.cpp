//
// Created by MOmac on 30.03.2019.
//

#include "ELFProgramHeader.h"

elf::ELFProgramHeader::ELFProgramHeader(elf::ELF &elf) : ELFStructureBase(elf), segment_data(nullptr) {}

char *elf::ELFProgramHeader::get_segment_data() const {
    return segment_data;
}

void elf::ELFProgramHeader::set_copy_of_segment_data(const char *raw_data, Elf_Word size) {
    delete[] this->segment_data;
    this->segment_data = nullptr;

    this->set_p_filesz(size);

    if (size == 0)
        return;

    this->segment_data = new char[size];
    std::copy(raw_data, raw_data + size, this->segment_data);
}

void elf::ELFProgramHeader::set_segment_data(char *raw_data, elf::Elf_Word size) {
    delete[] this->segment_data;
    this->segment_data = raw_data;
    this->set_p_filesz(size);
}

unsigned int elf::ELFProgramHeader::get_index() const {
    return index;
}

void elf::ELFProgramHeader::set_index(unsigned int index) {
    ELFProgramHeader::index = index;
}
