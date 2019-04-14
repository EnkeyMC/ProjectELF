#include "gui/diagram/nodes/DiagramSectionHeaderNode.h"

DiagramSectionHeaderNode::DiagramSectionHeaderNode(
        DiagramScene *diagram,
        ELFSectionHeaderModelItem *sectionHeaderModelItem
        )
    : DiagramELFNode (diagram, sectionHeaderModelItem),
      sectionHeaderModelItem(sectionHeaderModelItem)
{

}

void DiagramSectionHeaderNode::paint(QPainter *painter) const
{
    painter->setBrush(QBrush(QColor(255, 255, 100)));
    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Section header");
}

int DiagramSectionHeaderNode::getMinHeight() const
{
    return 20;
}
