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

void DiagramELFNode::paintAddress(QPainter *painter) const {
    painter->setPen(QColor(0, 0, 0, 100));
    painter->drawText(this->nodeRect.adjusted(5, 5, -5, -5), QString("Addr: 0x") + QString::number(modelItem->getAddressInFile(), 16));
}

void DiagramELFNode::paintSize(QPainter *painter) const {
    painter->setPen(QColor(0, 0, 0, 100));
    painter->drawText(this->nodeRect.adjusted(5, 5, -5, -5), Qt::AlignRight, QString("Size: ") + QString::number(modelItem->getSizeInFile()) + " B");
}
