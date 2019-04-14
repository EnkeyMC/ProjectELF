//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionHeaderModelItem.h"

ELFSectionHeaderModelItem::ELFSectionHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    sectionModelItem = new ELFSectionModelItem(parent, this->elf, this->index);
}

ELFSectionHeaderModelItem::~ELFSectionHeaderModelItem() {
    delete sectionModelItem;
}

ELFSectionModelItem *ELFSectionHeaderModelItem::getSectionModelItem() const
{
    return this->sectionModelItem;
}
