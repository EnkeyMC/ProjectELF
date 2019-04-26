//
// Created by MOmac on 14.04.2019.
//

#ifndef PROJECTELF_DIAGRAMSECTIONNODE_H
#define PROJECTELF_DIAGRAMSECTIONNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "core/models/ELFSectionModelItem.h"

class DiagramSectionNode : public DiagramELFNode {
    Q_OBJECT
public:
    DiagramSectionNode(DiagramScene *diagram, ELFSectionModelItem *sectionModel);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

private:
    ELFSectionModelItem *sectionModel;
};


#endif //PROJECTELF_DIAGRAMSECTIONNODE_H
