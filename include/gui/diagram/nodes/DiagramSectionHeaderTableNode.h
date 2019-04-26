//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
#define PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H

#include "gui/diagram/nodes/DiagramTableNode.h"
#include "gui/diagram/nodes/DiagramSectionHeaderNode.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"

class DiagramSectionHeaderTableNode : public DiagramTableNode<DiagramSectionHeaderNode> {
    Q_OBJECT
public:
    DiagramSectionHeaderTableNode(DiagramScene *diagram, ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem);

    ~DiagramSectionHeaderTableNode() override;

    DiagramSectionHeaderNode *getSectionHeaderNode(unsigned index);

protected:
    vector<DiagramSectionHeaderNode *> &getTableEntries() override;

    const vector<DiagramSectionHeaderNode *> &getTableEntries() const override;

private:
    ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem;

    std::vector<DiagramSectionHeaderNode *> sectionHeaderNodes;
};


#endif //PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
