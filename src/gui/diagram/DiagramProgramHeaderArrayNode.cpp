//
// Created by MOmac on 13.03.2019.
//

#include "gui/diagram/DiagramProgramHeaderArrayNode.h"

DiagramProgramHeaderArrayNode::DiagramProgramHeaderArrayNode(DiagramScene *diagram) : DiagramELFNode(diagram) {

}

void DiagramProgramHeaderArrayNode::paint(QPainter *painter) const {

}

int DiagramProgramHeaderArrayNode::getMinHeight() const {
    return 100;
}
