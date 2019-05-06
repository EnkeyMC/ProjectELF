//
// Created by MOmac on 23.03.2019.
//

#include "ELFSectionHeader.h"
#include "ELF.h"

namespace elf {

ELFSectionHeader::ELFSectionHeader(ELF &elf) : ELFStructureBase(elf), section_data(nullptr), index(0) {

}

char *ELFSectionHeader::get_section_data() const {
    return section_data;
}

void ELFSectionHeader::set_copy_of_section_data(const char *raw_data, Elf_Word size) {
    delete[] this->section_data;
    this->section_data = nullptr;

    this->set_sh_size(size);

    if (size == 0)
        return;

    this->section_data = new char[size+1];
    std::copy(raw_data, raw_data + size, this->section_data);
    this->section_data[size] = '\0';  // Ensure null termination
}

unsigned int ELFSectionHeader::get_index() const {
    return index;
}

void ELFSectionHeader::set_index(unsigned int index) {
    ELFSectionHeader::index = index;
}

}
