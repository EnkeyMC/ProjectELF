//
// Created by MOmac on 09.03.2019.
//

#include "gui/diagram/DiagramHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramHeaderNode::DiagramHeaderNode(DiagramScene *diagram) : DiagramELFNode(diagram, 0, 0.2) {
    this->colspan = 2;
}

void DiagramHeaderNode::paint(QPainter *painter) const {
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "ELF Header");
}

int DiagramHeaderNode::getMinHeight() const {
    return 50;
}
