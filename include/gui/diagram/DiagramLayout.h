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

    virtual int getContentWidth() const = 0;

    virtual int getArrowSpace() const = 0;

    int getMinWidth() const;

    void addLinkNode(DiagramNode *node);

    void addExecNode(DiagramNode *node);

    void clearNodes();

    const std::set<DiagramNode *> &getLinkColumnSortedNodes() const;

    const std::set<DiagramNode *> &getExecColumnSortedNodes() const;

    virtual QPoint getNodeOffset() const = 0;

    typedef std::function<void(DiagramNode &)> NodeCallback;
    void forEachLinkNode(const NodeCallback &callback);
    void forEachExecNode(const NodeCallback &callback);
    void forEachNode(const NodeCallback &callback);

signals:
    void layoutChanged();

protected:

    DiagramScene *diagram;
    std::set<DiagramNode *> linkColumnSortedNodes;
    std::set<DiagramNode *> execColumnSortedNodes;

    QSize size;
    int minWidth;
};


#endif //PROJECTELF_DIAGRAMLAYOUT_H
