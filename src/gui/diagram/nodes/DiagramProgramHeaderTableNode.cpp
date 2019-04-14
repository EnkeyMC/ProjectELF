//
// Created by MOmac on 13.03.2019.
//

#include "gui/diagram/nodes/DiagramProgramHeaderTableNode.h"

DiagramProgramHeaderTableNode::DiagramProgramHeaderTableNode(
        DiagramScene *diagram,
        ELFProgramHeaderTableModelItem *programHeaderTableModelItem
)
        : DiagramELFNode(diagram, programHeaderTableModelItem),
          programHeaderTableModelItem(programHeaderTableModelItem)
{
    connect(this, &DiagramNode::nodeRectChanged, this, &DiagramProgramHeaderTableNode::onNodeRectChanged);

    auto headerModels = programHeaderTableModelItem->getProgramHeaders();
    for (auto headerModel : headerModels) {
        programHeaderNodes.push_back(new DiagramProgramHeaderNode(diagram, headerModel));
    }
}

void DiagramProgramHeaderTableNode::paint(QPainter *painter) const {
    painter->setBrush(QBrush(QColor(100, 100, 255)));
    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(nodeRect);

    for (auto headerNode : programHeaderNodes) {
        headerNode->paint(painter);
    }
}

int DiagramProgramHeaderTableNode::getMinHeight() const {
    int sum = 0;
    for (auto programHeaderNode : programHeaderNodes)
        sum += programHeaderNode->getMinHeight();
    return sum;
}

DiagramProgramHeaderNode *DiagramProgramHeaderTableNode::getProgramHeaderNode(unsigned index)
{
    return programHeaderNodes[index];
}

void DiagramProgramHeaderTableNode::onNodeRectChanged() {

}
