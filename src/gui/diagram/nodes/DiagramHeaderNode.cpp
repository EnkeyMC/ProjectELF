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
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "ELF Header");
}

int DiagramHeaderNode::getMinHeight() const {
    return 50;
}
