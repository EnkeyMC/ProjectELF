//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
#define PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "gui/diagram/nodes/DiagramSectionHeaderNode.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"

class DiagramSectionHeaderTableNode : public DiagramELFNode {
    Q_OBJECT
public:
    DiagramSectionHeaderTableNode(DiagramScene *diagram, ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem);

    ~DiagramSectionHeaderTableNode() override;

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

    DiagramSectionHeaderNode *getSectionHeaderNode(unsigned index);

private:
    ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem;

    std::vector<DiagramSectionHeaderNode *> sectionHeaderNodes;
};


#endif //PROJECTELF_DIAGRAMSECTIONHEADERSNODE_H
