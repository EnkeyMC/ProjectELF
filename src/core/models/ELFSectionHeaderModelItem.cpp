//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionHeaderModelItem.h"

ELFSectionHeaderModelItem::ELFSectionHeaderModelItem(ELFModel *parent) : ELFModelItem(parent) {}

ELFSectionHeaderModelItem::~ELFSectionHeaderModelItem() {
    delete sectionModelItem;
}
