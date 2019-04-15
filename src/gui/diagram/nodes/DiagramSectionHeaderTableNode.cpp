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
    auto headerModels = sectionHeaderTableModelItem->getSectionHeaders();
    for (auto headerModel : headerModels) {
        sectionHeaderNodes.push_back(new DiagramSectionHeaderNode(diagram, headerModel));
    }
}

DiagramSectionHeaderTableNode::~DiagramSectionHeaderTableNode()
{
    for (auto headerNode : sectionHeaderNodes)
        delete headerNode;
}

void DiagramSectionHeaderTableNode::paint(QPainter *painter) const {
    painter->setBrush(QBrush(QColor(255, 100, 100)));
    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(nodeRect);

    for (auto headerNode : sectionHeaderNodes) {
        headerNode->paint(painter);
    }
    this->paintAddress(painter);
    this->paintSize(painter);
}

int DiagramSectionHeaderTableNode::getMinHeight() const {
    int sum = 0;
    for (auto sectionHeaderNode : sectionHeaderNodes)
        sum += sectionHeaderNode->getMinHeight();
    return sum;
}

DiagramSectionHeaderNode *DiagramSectionHeaderTableNode::getSectionHeaderNode(unsigned index)
{
    return sectionHeaderNodes[index];
}
