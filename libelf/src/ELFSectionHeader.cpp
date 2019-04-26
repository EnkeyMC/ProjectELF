//
// Created by MOmac on 23.03.2019.
//

#include "ELFSectionHeader.h"
#include "ELF.h"

namespace elf {

ELFSectionHeader::ELFSectionHeader(ELF &elf) : ELFStructureBase(elf), section_data(nullptr) {

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

    this->section_data = new char[size];
    std::copy(raw_data, raw_data + size, this->section_data);
}

void ELFSectionHeader::set_section_data(char *raw_data, Elf_Word size) {
    delete[] this->section_data;
    this->section_data = raw_data;
    this->set_sh_size(size);
}

}
