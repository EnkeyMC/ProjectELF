//
// Created by MOmac on 09.03.2019.
//

#include "gui/diagram/DiagramHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramHeaderNode::DiagramHeaderNode(DiagramScene *diagram) : DiagramNode(diagram) {
    this->colspan = 2;
}

void DiagramHeaderNode::paint(QPainter *painter) const {
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "ELF Header");
}

double DiagramHeaderNode::getProportionalPosition() const {
    return 0;
}

double DiagramHeaderNode::getProportionalSize() const {
    return 0.2;
}

int DiagramHeaderNode::getMinHeight() const {
    return 50;
}
