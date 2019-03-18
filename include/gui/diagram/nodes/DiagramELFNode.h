//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMELFNODE_H
#define PROJECTELF_DIAGRAMELFNODE_H

#include "gui/diagram/DiagramNode.h"
#include "include/core/models/ELFModelItem.h"

class DiagramELFNode : public DiagramNode {
public:
    explicit DiagramELFNode(DiagramScene *diagram, ELFModelItem *modelItem);

    double getProportionalPosition() const override;

    double getProportionalSize() const override;

protected:
    double proportionalPosition;
    double proportionalSize;

    ELFModelItem *modelItem;
};


#endif //PROJECTELF_DIAGRAMELFNODE_H
