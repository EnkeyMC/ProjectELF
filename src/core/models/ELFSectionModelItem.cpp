//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionModelItem.h"

ELFSectionModelItem::ELFSectionModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    auto sectionHeader = this->elf->get_section_headers()[this->index];
    this->sizeInFile = sectionHeader->get_sh_size();
    this->addressInFile = sectionHeader->get_sh_offset();
}

bool ELFSectionModelItem::isValid() const {
    return this->elf->get_section_headers()[this->index]->is_section_valid();
}
