//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramSectionNode.h"

DiagramSectionNode::DiagramSectionNode(DiagramScene *diagram, ELFSectionModelItem *sectionModel)
    : DiagramELFNode (diagram, sectionModel), sectionModel(sectionModel)
{

}

void DiagramSectionNode::paint(QPainter *painter) const
{
    painter->setBrush(QBrush(QColor(50, 255, 50)));
    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Section");
}

int DiagramSectionNode::getMinHeight() const
{
    return 20;
}
