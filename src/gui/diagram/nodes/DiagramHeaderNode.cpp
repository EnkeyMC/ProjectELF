//
// Created by MOmac on 09.03.2019.
//

#include "gui/diagram/nodes/DiagramHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramHeaderNode::DiagramHeaderNode(DiagramScene *diagram, ELFHeaderModelItem *modelItem) : DiagramELFNode(diagram, modelItem) {
    this->colspan = 2;
    this->headerModelItem = modelItem;

    auto sht = modelItem->getSectionHeaderTable();
    auto shtOffset = sht == nullptr ? ConnectionPoint::INVALID_ADDRESS : sht->getAddressInFile();
    auto pht = modelItem->getProgramHeaderTable();
    auto phtOffset = pht == nullptr ? ConnectionPoint::INVALID_ADDRESS : pht->getAddressInFile();

    this->registerConnectionPoint(new ConnectionPoint("e_shoff", ConnectionPoint::LEFT, shtOffset));
    this->registerConnectionPoint(new ConnectionPoint("e_phoff", ConnectionPoint::RIGHT, phtOffset));
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
    return 30;
}

void DiagramHeaderNode::mousePressEvent(QMouseEvent *event) {
    DiagramNode::mousePressEvent(event);
}
