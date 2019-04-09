//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderModelItem.h"

ELFProgramHeaderModelItem::ELFProgramHeaderModelItem(ELFModel *parent)
    : ELFModelItem(parent),
      segmentModelItem(nullptr)
{}

ELFProgramHeaderModelItem::~ELFProgramHeaderModelItem() {
    delete segmentModelItem;
}
