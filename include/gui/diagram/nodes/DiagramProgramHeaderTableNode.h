//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
#define PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"

class DiagramProgramHeaderTableNode : public DiagramELFNode {
public:
    explicit DiagramProgramHeaderTableNode(DiagramScene *diagram, ELFProgramHeaderTableModelItem *programHeaderTableModelItem);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

private:
    ELFProgramHeaderTableModelItem *programHeaderTableModelItem;
};


#endif //PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
