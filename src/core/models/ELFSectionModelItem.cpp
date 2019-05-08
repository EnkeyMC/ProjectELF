//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionModelItem.h"

ELFSectionModelItem::ELFSectionModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    onStructureChanged();
}

bool ELFSectionModelItem::isValid() const {
    return this->elf->get_section_headers()[this->index]->is_section_valid();
}

void ELFSectionModelItem::onStructureChanged() {
    auto sectionHeader = this->elf->get_section_headers()[this->index];
    if (sectionHeader->is_section_valid()) {
        this->sizeInFile = sectionHeader->get_sh_size();
        this->addressInFile = sectionHeader->get_sh_offset();
    } else {
        sizeInFile = 0;
        addressInFile = 0;
    }
}
