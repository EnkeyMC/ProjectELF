//
// Created by MOmac on 13.03.2019.
//

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "core/models/ELFModel.h"

DiagramELFNode::DiagramELFNode(DiagramScene *diagram, ELFModelItem *modelItem)
    : DiagramNode(diagram),
      modelItem(modelItem)
{
    double fileSize = modelItem->getModel()->getFileSize();
    this->proportionalPosition = modelItem->getAddressInFile() / fileSize;
    this->proportionalSize = modelItem->getSizeInFile() / fileSize;
}

double DiagramELFNode::getProportionalPosition() const {
    return proportionalPosition;
}

double DiagramELFNode::getProportionalSize() const {
    return proportionalSize;
}
