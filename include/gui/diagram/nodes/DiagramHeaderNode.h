//
// Created by MOmac on 09.03.2019.
//

#ifndef PROJECTELF_DIAGRAMHEADERNODE_H
#define PROJECTELF_DIAGRAMHEADERNODE_H

#include "include/gui/diagram/nodes/DiagramELFNode.h"
#include "include/core/models/ELFHeaderModelItem.h"

class DiagramHeaderNode : public DiagramELFNode {
public:
    explicit DiagramHeaderNode(DiagramScene *diagram, ELFHeaderModelItem *modelItem);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

protected:
    ELFHeaderModelItem *headerModelItem;
};


#endif //PROJECTELF_DIAGRAMHEADERNODE_H
