//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMELFNODE_H
#define PROJECTELF_DIAGRAMELFNODE_H

#include "gui/diagram/DiagramNode.h"

class DiagramELFNode : public DiagramNode {
public:
    explicit DiagramELFNode(DiagramScene *diagram, double proportionalPosition = 0, double proportionalSize = 0);

    double getProportionalPosition() const override;

    double getProportionalSize() const override;

protected:
    double proportionalPosition;
    double proportionalSize;
};


#endif //PROJECTELF_DIAGRAMELFNODE_H
