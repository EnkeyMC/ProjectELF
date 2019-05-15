//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramSegmentNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramSegmentNode::DiagramSegmentNode(DiagramScene *diagram, ELFSegmentModelItem *segmentModel)
    : DiagramELFNode (diagram, segmentModel), segmentModel(segmentModel)
{
    this->viewSide = DiagramNode::RIGHT;
    this->column = 3;
}

void DiagramSegmentNode::paint(QPainter *painter) const
{
    DiagramELFNode::paint(painter);
    painter->setBrush(diagram->getStyle()->getSegmentNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect.adjusted(5, 5, -5, 0), Qt::AlignTop | Qt::AlignHCenter,
            "Segment #" + QString::number(segmentModel->getIndex()) + "\n" +
            segmentModel->getType()
    );
    this->paintAddress(painter);
    this->paintSize(painter);
}

int DiagramSegmentNode::getMinHeight() const
{
    return 30;
}
