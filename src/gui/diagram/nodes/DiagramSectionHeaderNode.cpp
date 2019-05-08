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
    uint64_t address = ConnectionPoint::INVALID_ADDRESS;
    if (sectionHeaderModelItem->getSectionModelItem() != nullptr)
        address = sectionHeaderModelItem->getSectionModelItem()->getAddressInFile();

    registerConnectionPoint(
            new ConnectionPoint("sh_offset", Side::LEFT, address)
    );
}

void DiagramSectionHeaderNode::paint(QPainter *painter) const
{
    DiagramELFNode::paint(painter);
    painter->setBrush(diagram->getStyle()->getSectionTableNodeBgr());
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Section header");
    this->paintAddress(painter);
    this->paintSize(painter);
    this->paintConnectionPoints(painter);
}

int DiagramSectionHeaderNode::getMinHeight() const
{
    return 20;
}

void DiagramSectionHeaderNode::hoverEnteredEvent(QHoverEvent *event) {
    emit hoverEntered();
}
