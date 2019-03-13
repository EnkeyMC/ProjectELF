//
// Created by MOmac on 13.03.2019.
//

#include "gui/diagram/DiagramELFNode.h"

DiagramELFNode::DiagramELFNode(DiagramScene *diagram, double proportionalPosition, double proportionalSize)
        : DiagramNode(diagram),
          proportionalPosition(proportionalPosition),
          proportionalSize(proportionalSize)
{

}

double DiagramELFNode::getProportionalPosition() const {
    return proportionalPosition;
}

double DiagramELFNode::getProportionalSize() const {
    return proportionalSize;
}
