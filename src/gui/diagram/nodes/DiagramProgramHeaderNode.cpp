//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramProgramHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramProgramHeaderNode::DiagramProgramHeaderNode(DiagramScene *diagram, ELFProgramHeaderModelItem *programHeaderModel)
    : DiagramELFNode (diagram, programHeaderModel),
      programHeaderModelItem(programHeaderModel)
{
    this->viewSide = DiagramNode::RIGHT;

    registerConnectionPoint(
            new ConnectionPoint("p_offset", Side::RIGHT)
    );
}

void DiagramProgramHeaderNode::paint(QPainter *painter) const
{
    DiagramELFNode::paint(painter);
    painter->setBrush(diagram->getStyle()->getProgramTableNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter,
            "Program header #" + QString::number(programHeaderModelItem->getIndex()) + "\n" +
            programHeaderModelItem->getDispType()
    );
    this->paintAddress(painter);
    this->paintSize(painter);
    this->paintConnectionPoints(painter);
}

int DiagramProgramHeaderNode::getMinHeight() const
{
    return 20;
}

void DiagramProgramHeaderNode::hoverEnteredEvent(QHoverEvent *event) {
    emit hoverEntered();
}
