//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
#define PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H

#include "gui/diagram/DiagramELFNode.h"

class DiagramSectionHeadersNode : public DiagramELFNode {
public:
    DiagramSectionHeadersNode(DiagramScene *diagram, double proportionalPosition, double proportionalSize);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;
};


#endif //PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
