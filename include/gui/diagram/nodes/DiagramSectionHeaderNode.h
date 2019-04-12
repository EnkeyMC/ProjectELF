#ifndef DIAGRAMSECTIONHEADERNODE_H
#define DIAGRAMSECTIONHEADERNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "gui/diagram/DiagramScene.h"

class DiagramSectionHeaderNode : public DiagramELFNode
{
public:
    DiagramSectionHeaderNode(DiagramScene *diagram, ELFSectionHeaderModelItem *sectionHeaderModelItem);

    void paint(QPainter *painter) const override;

    double getProportionalPosition() const override;

    double getProportionalSize() const override;

    int getMinHeight() const override;

private:
    ELFSectionHeaderModelItem *sectionHeaderModelItem;
};

#endif // DIAGRAMSECTIONHEADERNODE_H
