#include "gui/diagram/nodes/DiagramSectionHeaderNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramSectionHeaderNode::DiagramSectionHeaderNode(
        DiagramScene *diagram,
        ELFSectionHeaderModelItem *sectionHeaderModelItem
        )
    : DiagramELFNode (diagram, sectionHeaderModelItem),
      sectionHeaderModelItem(sectionHeaderModelItem)
{
    this->viewSide = DiagramNode::LEFT;

    registerConnectionPoint(
            new ConnectionPoint("sh_offset", Side::LEFT)
    );
}

void DiagramSectionHeaderNode::paint(QPainter *painter) const
{
    DiagramELFNode::paint(painter);
    painter->setBrush(diagram->getStyle()->getSectionTableNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter,
            "Section header #" +
            QString::number(sectionHeaderModelItem->getIndex()) +
            "\n" + sectionHeaderModelItem->getDispName()
    );
    this->paintAddress(painter);
    this->paintSize(painter);
    this->paintConnectionPoints(painter);
}

int DiagramSectionHeaderNode::getMinHeight() const
{
    return 40;
}

void DiagramSectionHeaderNode::hoverEnteredEvent(QHoverEvent *event) {
    emit hoverEntered();
}
