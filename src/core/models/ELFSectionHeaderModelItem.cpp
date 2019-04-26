//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionHeaderModelItem.h"

ELFSectionHeaderModelItem::ELFSectionHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    auto header = this->elf->get_header();
    sizeInFile = header->get_e_shentsize();
    addressInFile = header->get_e_shoff() + index * header->get_e_shentsize();
    sectionModelItem = new ELFSectionModelItem(parent, this->elf, this->index);
}

ELFSectionHeaderModelItem::~ELFSectionHeaderModelItem() {
    delete sectionModelItem;
}

ELFSectionModelItem *ELFSectionHeaderModelItem::getSectionModelItem() const
{
    return this->sectionModelItem;
}
