//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
#define PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H

#include "gui/diagram/nodes/DiagramTableNode.h"
#include "gui/diagram/nodes/DiagramProgramHeaderNode.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"

class DiagramProgramHeaderTableNode : public DiagramTableNode<DiagramProgramHeaderNode> {
    Q_OBJECT
public:
    explicit DiagramProgramHeaderTableNode(DiagramScene *diagram, ELFProgramHeaderTableModelItem *programHeaderTableModelItem);

    ~DiagramProgramHeaderTableNode() override;

    DiagramProgramHeaderNode *getProgramHeaderNode(unsigned index);

protected:
    vector<DiagramProgramHeaderNode *> &getTableEntries() override;

    const vector<DiagramProgramHeaderNode *> &getTableEntries() const override;

    const QBrush &getBrush() const override;

    const QPen &getPen() const override;

private:
    ELFProgramHeaderTableModelItem *programHeaderTableModelItem;

    std::vector<DiagramProgramHeaderNode *> programHeaderNodes;
};


#endif //PROJECTELF_DIAGRAMPROGRAMHEADERARRAYNODE_H
