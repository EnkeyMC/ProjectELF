//
// Created by MOmac on 13.03.2019.
//

#include "gui/diagram/nodes/DiagramProgramHeaderTableNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramProgramHeaderTableNode::DiagramProgramHeaderTableNode(
        DiagramScene *diagram,
        ELFProgramHeaderTableModelItem *programHeaderTableModelItem
)
        : DiagramTableNode(diagram, programHeaderTableModelItem),
          programHeaderTableModelItem(programHeaderTableModelItem)
{
    this->viewSide = DiagramNode::RIGHT;
    this->column = 2;
    auto headerModels = programHeaderTableModelItem->getProgramHeaders();
    for (auto headerModel : headerModels) {
        auto programHeaderNode = new DiagramProgramHeaderNode(diagram, headerModel);
        addHoverableChild(programHeaderNode);
        programHeaderNodes.push_back(programHeaderNode);
    }
}

DiagramProgramHeaderTableNode::~DiagramProgramHeaderTableNode() {
    for (auto node : programHeaderNodes)
        delete node;
}

DiagramProgramHeaderNode *DiagramProgramHeaderTableNode::getProgramHeaderNode(unsigned index)
{
    return programHeaderNodes[index];
}

vector<DiagramProgramHeaderNode *> &DiagramProgramHeaderTableNode::getTableEntries() {
    return programHeaderNodes;
}

const vector<DiagramProgramHeaderNode *> &DiagramProgramHeaderTableNode::getTableEntries() const {
    return programHeaderNodes;
}
