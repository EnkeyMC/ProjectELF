//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionHeaderModelItem.h"

ELFSectionHeaderModelItem::ELFSectionHeaderModelItem(ELFModel *parent, elf::ELFSectionHeader *sectionHeader)
    : ELFModelItem(parent),
      sectionHeader(sectionHeader)
{
    sectionModelItem = new ELFSectionModelItem(parent);
}

ELFSectionHeaderModelItem::~ELFSectionHeaderModelItem() {
    delete sectionModelItem;
}
