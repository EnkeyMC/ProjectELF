//
// Created by MOmac on 09.03.2019.
//

#ifndef PROJECTELF_DIAGRAMHEADERNODE_H
#define PROJECTELF_DIAGRAMHEADERNODE_H

#include "gui/diagram/DiagramELFNode.h"

class DiagramHeaderNode : public DiagramELFNode {
public:
    explicit DiagramHeaderNode(DiagramScene *diagram);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;
};


#endif //PROJECTELF_DIAGRAMHEADERNODE_H
