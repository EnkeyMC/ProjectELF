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
    this->viewSide = DiagramNode::LEFT;
    this->column = 1;
    auto headerModels = sectionHeaderTableModelItem->getSectionHeaders();
    for (auto headerModel : headerModels) {
        auto sectionHeaderNode = new DiagramSectionHeaderNode(diagram, headerModel);
        addHoverableChild(sectionHeaderNode);
        sectionHeaderNodes.push_back(sectionHeaderNode);
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
