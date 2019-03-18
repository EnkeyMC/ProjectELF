//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderTableModelItem.h"

ELFProgramHeaderTableModelItem::ELFProgramHeaderTableModelItem(ELFModel *parent) : ELFModelItem(parent) {}

ELFProgramHeaderTableModelItem::~ELFProgramHeaderTableModelItem() {
    for (auto programHeaderModelItem : this->programHeaderModelItems)
        delete programHeaderModelItem;
}
