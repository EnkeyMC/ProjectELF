//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
#define PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"

class DiagramSectionHeaderTableNode : public DiagramELFNode {
public:
    DiagramSectionHeaderTableNode(DiagramScene *diagram, ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

private:
    ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem;
};


#endif //PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
