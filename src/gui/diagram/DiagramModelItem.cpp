//
// Created by MOmac on 13.03.2019.
//

#include "gui/diagram/DiagramModelItem.h"
#include "gui/diagram/DiagramModel.h"

DiagramModelItem::DiagramModelItem(DiagramModel *parent) : QObject(parent) {}

uint64_t DiagramModelItem::getAddressInFile() const {
    return addressInFile;
}

uint64_t DiagramModelItem::getSizeInFile() const {
    return sizeInFile;
}
