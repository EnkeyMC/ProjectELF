//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMLAYOUT_H
#define PROJECTELF_DIAGRAMLAYOUT_H

#include <QPainter>
#include <QPointer>
#include <QObject>
#include <set>

#include "DiagramNode.h"

class DiagramScene;

class DiagramLayout : public QObject {
    Q_OBJECT

public:
    explicit DiagramLayout(DiagramScene *diagram);

    virtual ~DiagramLayout() {}

    virtual void layoutNodes() = 0;

    virtual void paint(QPainter *painter) const = 0;

    void addLinkNode(DiagramNode *node);

    void addExecNode(DiagramNode *node);

protected:
    DiagramScene *diagram;
    std::set<DiagramNode *> m_linkColumnSortedNodes;
    std::set<DiagramNode *> m_execColumnSortedNodes;
};


#endif //PROJECTELF_DIAGRAMLAYOUT_H
