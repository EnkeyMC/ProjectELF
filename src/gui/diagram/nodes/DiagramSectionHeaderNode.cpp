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
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Section header");
}

double DiagramSectionHeaderNode::getProportionalPosition() const
{
    return static_cast<double>(sectionHeaderModelItem->getAddressInFile())
            /
            sectionHeaderModelItem->getModel()->getFileSize();
}

double DiagramSectionHeaderNode::getProportionalSize() const
{
    return static_cast<double>(sectionHeaderModelItem->getSizeInFile())
            /
            sectionHeaderModelItem->getModel()->getFileSize();
}

int DiagramSectionHeaderNode::getMinHeight() const
{
    return 20;
}
