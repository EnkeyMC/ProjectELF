//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_DIAGRAMLAYOUT_H
#define PROJECTELF_DIAGRAMLAYOUT_H

#include <QPainter>
#include <QPointer>
#include <QObject>
#include <map>
#include <functional>
#include <deque>
#include <ELFTypes.h>

#include "DiagramNode.h"

class DiagramScene;

class DiagramLayout : public QObject {
    Q_OBJECT

public:
    typedef std::multimap<DiagramNode *, int, DiagramNode::PtrComparer> SortedNodesType;

    explicit DiagramLayout(DiagramScene *diagram);

    virtual ~DiagramLayout() {}

    virtual void layoutNodes();

    virtual void paint(QPainter *painter) const = 0;

    virtual QSize getSize() const;

    virtual int getContentWidth() const = 0;

    virtual int getArrowSpace() const = 0;

    int getMinWidth() const;

    void addNode(DiagramNode *node);

    void clearNodes();

    const SortedNodesType &getLinkColumnSortedNodes() const;

    const SortedNodesType &getExecColumnSortedNodes() const;

    const std::deque<DiagramNode *> &getNodesZOrdered() const;

    virtual QPoint getNodeOffset() const = 0;

    typedef std::function<void(DiagramNode &)> NodeCallback;
    void forEachLinkNode(const NodeCallback &callback);
    void forEachExecNode(const NodeCallback &callback);
    void forEachNode(const NodeCallback &callback);

signals:
    void layoutChanged();
    void zOrderChanged();

public slots:
    void pushToFront(DiagramNode *node);

protected:
    std::function<bool(const SortedNodesType::value_type &)> getPairEqualityComparer(DiagramNode *node) const;

    SortedNodesType::iterator findNode(SortedNodesType &nodes, DiagramNode *node);
    SortedNodesType::const_iterator findNode(const SortedNodesType &nodes, DiagramNode *node) const;

    SortedNodesType::iterator getNodeIterator(DiagramNode *node);
    SortedNodesType::const_iterator getNodeIterator(DiagramNode *node) const;

    SortedNodesType::iterator getEndIterator(DiagramNode::ViewSide side);
    SortedNodesType::const_iterator getEndIterator(DiagramNode::ViewSide side) const;

    DiagramScene *diagram;
    SortedNodesType linkColumnSortedNodes;
    SortedNodesType execColumnSortedNodes;

    std::deque<DiagramNode *> nodesZOrdered;

    QSize size;
    int minWidth;
};


#endif //PROJECTELF_DIAGRAMLAYOUT_H
