//
// Created by MOmac on 10.03.2019.
//

#include <QPainter>

#include "gui/diagram/DiagramSectionHeadersNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramSectionHeadersNode::DiagramSectionHeadersNode(DiagramScene *diagram, double proportionalPosition, double proportionalSize)
    : DiagramNode(diagram),
    proportionalPosition(proportionalPosition),
    proportionalSize(proportionalSize)
{

}

void DiagramSectionHeadersNode::paint(QPainter *painter) const {
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Section headers");
}

double DiagramSectionHeadersNode::getProportionalPosition() const {
    return proportionalPosition;
}

double DiagramSectionHeadersNode::getProportionalSize() const {
    return proportionalSize;
}

int DiagramSectionHeadersNode::getMinHeight() const {
    return 100;
}
