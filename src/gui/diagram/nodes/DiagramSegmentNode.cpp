//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramSegmentNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramSegmentNode::DiagramSegmentNode(DiagramScene *diagram, ELFSegmentModelItem *segmentModel)
    : DiagramELFNode (diagram, segmentModel), segmentModel(segmentModel)
{

}

void DiagramSegmentNode::paint(QPainter *painter) const
{
    painter->setBrush(diagram->getStyle()->getSegmentNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Segment");
    this->paintAddress(painter);
    this->paintSize(painter);
}

int DiagramSegmentNode::getMinHeight() const
{
    return 20;
}
