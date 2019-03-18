//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionHeaderTableModelItem.h"

ELFSectionHeaderTableModelItem::ELFSectionHeaderTableModelItem(ELFModel *parent) : ELFModelItem(parent) {}

ELFSectionHeaderTableModelItem::~ELFSectionHeaderTableModelItem() {
    for (auto sectionHeaderModelItem : this->sectionHeaderModelItems)
        delete sectionHeaderModelItem;
}
