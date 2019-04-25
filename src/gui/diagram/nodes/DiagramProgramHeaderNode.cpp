//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramProgramHeaderNode.h"

DiagramProgramHeaderNode::DiagramProgramHeaderNode(DiagramScene *diagram, ELFProgramHeaderModelItem *programHeaderModel)
    : DiagramELFNode (diagram, programHeaderModel),
      programHeaderModelItem(programHeaderModel)
{

}

void DiagramProgramHeaderNode::paint(QPainter *painter) const
{
    DiagramELFNode::paint(painter);
    painter->setBrush(QBrush(QColor(100, 255, 255)));
    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Program header");
}

int DiagramProgramHeaderNode::getMinHeight() const
{
    return 20;
}
