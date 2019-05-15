//
// Created by MOmac on 09.03.2019.
//

#include "gui/diagram/nodes/DiagramHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramHeaderNode::DiagramHeaderNode(DiagramScene *diagram, ELFHeaderModelItem *modelItem) : DiagramELFNode(diagram, modelItem) {
    this->viewSide = BOTH;
    this->column = 1;
    this->colspan = 2;
    this->headerModelItem = modelItem;

    this->registerConnectionPoint(new ConnectionPoint("e_shoff", Side::LEFT));
    this->registerConnectionPoint(new ConnectionPoint("e_phoff", Side::RIGHT));
}

void DiagramHeaderNode::paint(QPainter *painter) const {
    DiagramELFNode::paint(painter);
    painter->setBrush(diagram->getStyle()->getHeaderNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "ELF Header");
    this->paintAddress(painter);
    this->paintSize(painter);
    this->paintConnectionPoints(painter);
}

int DiagramHeaderNode::getMinHeight() const {
    return 40;
}

void DiagramHeaderNode::mousePressEvent(QMouseEvent *event) {
    DiagramNode::mousePressEvent(event);
}
