//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
#define PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H

#include "gui/diagram/DiagramELFNode.h"

class DiagramProgramHeaderArrayNode : public DiagramELFNode {
public:
    explicit DiagramProgramHeaderArrayNode(DiagramScene *diagram);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;
};


#endif //PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
