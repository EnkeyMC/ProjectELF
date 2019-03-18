//
// Created by MOmac on 15.03.2019.
//

#include "core/models/ELFHeaderModelItem.h"

ELFHeaderModelItem::ELFHeaderModelItem(ELFModel *parent) : ELFModelItem(parent) {

}

ELFHeaderModelItem::~ELFHeaderModelItem() {
    delete sectionHeaderTableModelItem;
    delete programHeaderTableModelItem;
}
