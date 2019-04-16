//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMLAYOUT_H
#define PROJECTELF_DIAGRAMLAYOUT_H

#include <QPainter>
#include <QPointer>
#include <QObject>
#include <set>
#include <functional>

#include "DiagramNode.h"

class DiagramScene;

class DiagramLayout : public QObject {
    Q_OBJECT

public:
    explicit DiagramLayout(DiagramScene *diagram);

    virtual ~DiagramLayout() {}

    virtual void layoutNodes();

    virtual void paint(QPainter *painter) const = 0;

    virtual QSize getSize() const;

    int getMinWidth() const;

    void addLinkNode(DiagramNode *node);

    void addExecNode(DiagramNode *node);

    void clearNodes();

    const std::set<DiagramNode *> &getLinkColumnSortedNodes() const;

    const std::set<DiagramNode *> &getExecColumnSortedNodes() const;

    virtual QPoint getNodeOffset() const = 0;

signals:
    void layoutChanged();

protected:
    typedef std::function<void(DiagramNode &)> NodeCallback;

    void forEachLinkNode(const NodeCallback &callback);

    void forEachExecNode(const NodeCallback &callback);

    void forEachNode(const NodeCallback &callback);

    DiagramScene *diagram;
    std::set<DiagramNode *> linkColumnSortedNodes;
    std::set<DiagramNode *> execColumnSortedNodes;

    QSize contentsSize;
    int minWidth;
};


#endif //PROJECTELF_DIAGRAMLAYOUT_H
