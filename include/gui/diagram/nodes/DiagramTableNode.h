//
// Created by MOmac on 25.04.2019.
//

#ifndef PROJECTELF_DIAGRAMTABLENODE_H
#define PROJECTELF_DIAGRAMTABLENODE_H

#include "gui/diagram/nodes/DiagramELFNode.h"

template <typename T>
class DiagramTableNode : public DiagramELFNode {
public:
    DiagramTableNode(DiagramScene *diagram, ELFModelItem *modelItem);

    void paint(QPainter *painter) const override;

    int getMinHeight() const override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void onNodeRectChanged();

protected:
    virtual std::vector<T *> &getTableEntries() = 0;

    virtual const std::vector<T *> &getTableEntries() const = 0;
};

template <typename T>
DiagramTableNode<T>::DiagramTableNode(DiagramScene *diagram, ELFModelItem *modelItem)
        : DiagramELFNode(diagram, modelItem)
{
    connect(this, &DiagramNode::nodeRectChanged, this, &DiagramTableNode::onNodeRectChanged);
}

template <typename T>
void DiagramTableNode<T>::paint(QPainter *painter) const {
    DiagramELFNode::paint(painter);

    this->paintConnectionPoints(painter);
    for (auto headerNode : getTableEntries()) {
        headerNode->paint(painter);
    }
}

template <typename T>
int DiagramTableNode<T>::getMinHeight() const {
    int sum = 0;
    for (auto programHeaderNode : getTableEntries())
        sum += programHeaderNode->getMinHeight();
    return sum;
}

template <typename T>
void DiagramTableNode<T>::onNodeRectChanged() {
    double entryHeight = 0;
    if (getTableEntries().size() > 0)
        entryHeight = static_cast<double>(nodeRect.height()) / getTableEntries().size();
    QRectF tmpRect{
        static_cast<qreal>(nodeRect.left()),
        static_cast<qreal>(nodeRect.top()),
        static_cast<qreal>(nodeRect.width()),
        entryHeight
    };
    auto tableEntries = getTableEntries();
    for (int i = 0; i < tableEntries.size(); i++) {
        auto node = tableEntries[i];
        node->setNodeRect(tmpRect.translated(0, entryHeight*i).toAlignedRect());
    }
}

template<typename T>
void DiagramTableNode<T>::mousePressEvent(QMouseEvent *event) {
    DiagramNode::mousePressEvent(event);
    for (auto entry : getTableEntries()) {
        if (entry->contains(event->pos()))
            entry->mousePressEvent(event);
    }
}

template<typename T>
void DiagramTableNode<T>::mouseReleaseEvent(QMouseEvent *event) {
    DiagramNode::mouseReleaseEvent(event);
    for (auto entry : getTableEntries()) {
        if (entry->contains(event->pos()))
            entry->mouseReleaseEvent(event);
    }
}

#endif //PROJECTELF_DIAGRAMTABLENODE_H
