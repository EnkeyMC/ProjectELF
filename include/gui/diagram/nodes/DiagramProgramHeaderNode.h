//
// Created by MOmac on 14.04.2019.
//

#ifndef PROJECTELF_DIAGRAMPROGRAMHEADERNODE_H
#define PROJECTELF_DIAGRAMPROGRAMHEADERNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "core/models/ELFProgramHeaderModelItem.h"

class DiagramProgramHeaderNode : public DiagramELFNode {
    Q_OBJECT
public:
    DiagramProgramHeaderNode(DiagramScene *diagram, ELFProgramHeaderModelItem *programHeaderModel);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

protected:
    void hoverEnteredEvent(QHoverEvent *event) override;

private:
    ELFProgramHeaderModelItem *programHeaderModelItem;
};


#endif //PROJECTELF_DIAGRAMPROGRAMHEADERNODE_H
