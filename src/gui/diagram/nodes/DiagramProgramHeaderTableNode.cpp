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
    auto headerModels = programHeaderTableModelItem->getProgramHeaders();
    for (auto headerModel : headerModels) {
        programHeaderNodes.push_back(new DiagramProgramHeaderNode(diagram, headerModel));
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

const QBrush &DiagramProgramHeaderTableNode::getBrush() const {
    return diagram->getStyle()->getProgramTableNodeBgr();
}

const QPen &DiagramProgramHeaderTableNode::getPen() const {
    return diagram->getStyle()->getDefaultPen();
}

vector<DiagramProgramHeaderNode *> &DiagramProgramHeaderTableNode::getTableEntries() {
    return programHeaderNodes;
}

const vector<DiagramProgramHeaderNode *> &DiagramProgramHeaderTableNode::getTableEntries() const {
    return programHeaderNodes;
}
