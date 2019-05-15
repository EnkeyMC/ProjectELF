//
// Created by MOmac on 14.04.2019.
//

#include "gui/diagram/nodes/DiagramSectionNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramSectionNode::DiagramSectionNode(DiagramScene *diagram, ELFSectionModelItem *sectionModel)
    : DiagramELFNode (diagram, sectionModel), sectionModel(sectionModel)
{
    this->viewSide = DiagramNode::LEFT;
    this->column = 0;
}

void DiagramSectionNode::paint(QPainter *painter) const
{
    DiagramELFNode::paint(painter);
    painter->setBrush(diagram->getStyle()->getSectionNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(this->nodeRect.adjusted(5, 5, -5, 0), Qt::AlignTop | Qt::AlignHCenter,
            "Section #" + QString::number(sectionModel->getIndex()) + "\n" +
            this->sectionModel->getName()
    );
    this->paintAddress(painter);
    this->paintSize(painter);
}

int DiagramSectionNode::getMinHeight() const
{
    return 30;
}
