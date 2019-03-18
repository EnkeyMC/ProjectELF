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

}

void DiagramProgramHeaderTableNode::paint(QPainter *painter) const {

}

int DiagramProgramHeaderTableNode::getMinHeight() const {
    return 100;
}
