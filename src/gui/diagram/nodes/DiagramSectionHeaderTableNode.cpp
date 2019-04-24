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
        : DiagramTableNode(diagram, sectionHeaderTableModelItem),
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

DiagramSectionHeaderNode *DiagramSectionHeaderTableNode::getSectionHeaderNode(unsigned index)
{
    return sectionHeaderNodes[index];
}

vector<DiagramSectionHeaderNode *> &DiagramSectionHeaderTableNode::getTableEntries() {
    return sectionHeaderNodes;
}

const vector<DiagramSectionHeaderNode *> &DiagramSectionHeaderTableNode::getTableEntries() const {
    return sectionHeaderNodes;
}

const QBrush &DiagramSectionHeaderTableNode::getBrush() const {
    return diagram->getStyle()->getSectionTableNodeBgr();
}

const QPen &DiagramSectionHeaderTableNode::getPen() const {
    return diagram->getStyle()->getDefaultPen();
}
