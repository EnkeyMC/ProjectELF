//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
#define PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H

#include "gui/diagram/DiagramNode.h"

class DiagramSectionHeadersNode : public DiagramNode {
public:
    DiagramSectionHeadersNode(DiagramScene *diagram, double proportionalPosition, double proportionalSize);

    void paint(QPainter *painter) const override;

    double getProportionalPosition() const override;

    double getProportionalSize() const override;

    int getMinHeight() const override;

protected:
    double proportionalPosition;
    double proportionalSize;
};


#endif //PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
