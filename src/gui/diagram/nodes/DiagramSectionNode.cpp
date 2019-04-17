//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramSectionNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramSectionNode::DiagramSectionNode(DiagramScene *diagram, ELFSectionModelItem *sectionModel)
    : DiagramELFNode (diagram, sectionModel), sectionModel(sectionModel)
{

}

void DiagramSectionNode::paint(QPainter *painter) const
{
    painter->setBrush(diagram->getStyle()->getSectionNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Section");
    this->paintAddress(painter);
    this->paintSize(painter);
}

int DiagramSectionNode::getMinHeight() const
{
    return 20;
}
