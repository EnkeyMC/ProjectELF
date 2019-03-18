//
// Created by MOmac on 13.03.2019.
//

#include "core/models/ELFModelItem.h"
#include "core/models/ELFModel.h"

ELFModelItem::ELFModelItem(ELFModel *parent) : QObject(parent) {}

uint64_t ELFModelItem::getAddressInFile() const {
    return addressInFile;
}

uint64_t ELFModelItem::getSizeInFile() const {
    return sizeInFile;
}

ELFModel *ELFModelItem::getModel() const {
    return dynamic_cast<ELFModel *>(this->parent());
}
