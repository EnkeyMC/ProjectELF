//
// Created by MOmac on 09.03.2019.
//

#include "gui/diagram/nodes/DiagramHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramHeaderNode::DiagramHeaderNode(DiagramScene *diagram, ELFHeaderModelItem *modelItem) : DiagramELFNode(diagram, modelItem) {
    this->colspan = 2;
    this->headerModelItem = modelItem;
}

void DiagramHeaderNode::paint(QPainter *painter) const {
    painter->setBrush(QBrush(QColor(255, 100, 255)));
    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "ELF Header");
    this->paintAddress(painter);
    this->paintSize(painter);
}

int DiagramHeaderNode::getMinHeight() const {
    return 50;
}
