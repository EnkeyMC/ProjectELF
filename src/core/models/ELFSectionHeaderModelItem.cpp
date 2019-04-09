//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionHeaderModelItem.h"

ELFSectionHeaderModelItem::ELFSectionHeaderModelItem(ELFModel *parent)
    : ELFModelItem(parent),
      sectionModelItem(nullptr)
{}

ELFSectionHeaderModelItem::~ELFSectionHeaderModelItem() {
    delete sectionModelItem;
}
