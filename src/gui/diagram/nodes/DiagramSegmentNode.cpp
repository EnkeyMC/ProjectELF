//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramSegmentNode.h"

DiagramSegmentNode::DiagramSegmentNode(DiagramScene *diagram, ELFSegmentModelItem *segmentModel)
    : DiagramELFNode (diagram, segmentModel), segmentModel(segmentModel)
{

}

void DiagramSegmentNode::paint(QPainter *painter) const
{
    painter->setBrush(QBrush(QColor(255, 50, 255)));
    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Segment");
    this->paintAddress(painter);
    this->paintSize(painter);
}

int DiagramSegmentNode::getMinHeight() const
{
    return 20;
}
