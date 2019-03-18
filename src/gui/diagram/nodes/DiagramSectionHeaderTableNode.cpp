//
// Created by MOmac on 10.03.2019.
//

#include <QPainter>

#include "gui/diagram/nodes/DiagramSectionHeaderTableNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramSectionHeaderTableNode::DiagramSectionHeaderTableNode(
        DiagramScene *diagram,
        ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem
)
        : DiagramELFNode(diagram, sectionHeaderTableModelItem),
          sectionHeaderTableModelItem(sectionHeaderTableModelItem)
{

}

void DiagramSectionHeaderTableNode::paint(QPainter *painter) const {
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(nodeRect);
    painter->drawText(nodeRect, Qt::AlignCenter, "Section headers");
}

int DiagramSectionHeaderTableNode::getMinHeight() const {
    return 100;
}
