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
    painter->setBrush(QBrush(QColor(255, 255, 255)));
    painter->drawRect(nodeRect);

    for (auto headerNode : sectionHeaderNodes) {
        headerNode->paint(painter);
    }
}

double DiagramSectionHeaderTableNode::getProportionalPosition() const
{
    return sectionHeaderTableModelItem->getAddressInFile()
            /
            static_cast<double>(sectionHeaderTableModelItem->getModel()->getFileSize());
}

double DiagramSectionHeaderTableNode::getProportionalSize() const
{
    return sectionHeaderTableModelItem->getSizeInFile()
            /
            static_cast<double>(sectionHeaderTableModelItem->getModel()->getFileSize());
}

int DiagramSectionHeaderTableNode::getMinHeight() const {
    return 100;
}
