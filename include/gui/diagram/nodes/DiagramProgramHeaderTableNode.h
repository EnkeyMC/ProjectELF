//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
#define PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "gui/diagram/nodes/DiagramProgramHeaderNode.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"

class DiagramProgramHeaderTableNode : public DiagramELFNode {
    Q_OBJECT
public:
    explicit DiagramProgramHeaderTableNode(DiagramScene *diagram, ELFProgramHeaderTableModelItem *programHeaderTableModelItem);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

    DiagramProgramHeaderNode *getProgramHeaderNode(unsigned index);

public slots:
    void onNodeRectChanged();

private:
    ELFProgramHeaderTableModelItem *programHeaderTableModelItem;

    std::vector<DiagramProgramHeaderNode *> programHeaderNodes;
};


#endif //PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
