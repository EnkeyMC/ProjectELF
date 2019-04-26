//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramProgramHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramProgramHeaderNode::DiagramProgramHeaderNode(DiagramScene *diagram, ELFProgramHeaderModelItem *programHeaderModel)
    : DiagramELFNode (diagram, programHeaderModel),
      programHeaderModelItem(programHeaderModel)
{
    registerConnectionPoint(
            new ConnectionPoint("p_offset", ConnectionPoint::RIGHT, programHeaderModel->getSegmentModelItem()->getAddressInFile())
    );
}

void DiagramProgramHeaderNode::paint(QPainter *painter) const
{
    DiagramELFNode::paint(painter);
    painter->setBrush(diagram->getStyle()->getProgramTableNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Program header");
    this->paintAddress(painter);
    this->paintSize(painter);
    this->paintConnectionPoints(painter);
}

int DiagramProgramHeaderNode::getMinHeight() const
{
    return 20;
}
