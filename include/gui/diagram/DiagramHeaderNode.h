//
// Created by MOmac on 09.03.2019.
//

#ifndef PROJECTELF_DIAGRAMHEADERNODE_H
#define PROJECTELF_DIAGRAMHEADERNODE_H

#include "DiagramNode.h"

class DiagramHeaderNode : public DiagramNode {
public:
    explicit DiagramHeaderNode(DiagramScene *diagram);

    void paint(QPainter *painter) const override;

    double getProportionalPosition() const override;

    double getProportionalSize() const override;

    int getMinHeight() const override;
};


#endif //PROJECTELF_DIAGRAMHEADERNODE_H
