//
// Created by MOmac on 14.04.2019.
//

#ifndef PROJECTELF_DIAGRAMSEGMENTNODE_H
#define PROJECTELF_DIAGRAMSEGMENTNODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"
#include "core/models/ELFSegmentModelItem.h"

class DiagramSegmentNode : public DiagramELFNode {
    Q_OBJECT
public:
    DiagramSegmentNode(DiagramScene *diagram, ELFSegmentModelItem *segmentModel);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;
private:
    ELFSegmentModelItem *segmentModel;
};


#endif //PROJECTELF_DIAGRAMSEGMENTNODE_H
