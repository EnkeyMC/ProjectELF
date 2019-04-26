//
// Created by MOmac on 10.03.2019.
//

#include <include/gui/diagram/DiagramLayout.h>

#include "gui/diagram/CondensedDiagramLayout.h"
#include "gui/diagram/DiagramLayout.h"
#include "gui/diagram/DiagramScene.h"

DiagramLayout::DiagramLayout(DiagramScene *diagram) : QObject(diagram) {
    this->diagram = diagram;
    this->minWidth = 0;
}

void DiagramLayout::addLinkNode(DiagramNode *node) {
    this->linkColumnSortedNodes.insert(node);
    node->setColumn(0);
}

void DiagramLayout::addExecNode(DiagramNode *node) {
    this->execColumnSortedNodes.insert(node);
    node->setColumn(1);
}

void DiagramLayout::clearNodes()
{
    for (auto node : linkColumnSortedNodes)
        delete node;
    for (auto node : execColumnSortedNodes)
        delete node;

    linkColumnSortedNodes.clear();
    execColumnSortedNodes.clear();
}

void DiagramLayout::forEachLinkNode(const NodeCallback &callback) {
    for (auto node : linkColumnSortedNodes)
        callback(*node);
}

void DiagramLayout::forEachExecNode(const NodeCallback &callback) {
    for (auto node : execColumnSortedNodes)
        callback(*node);
}

void DiagramLayout::forEachNode(const NodeCallback &callback) {
    forEachLinkNode(callback);
    forEachExecNode(callback);
}

QSize DiagramLayout::getSize() const {
    return size;
}

int DiagramLayout::getMinWidth() const {
    return minWidth;
}

void DiagramLayout::layoutNodes() {
    emit layoutChanged();
}

const std::set<DiagramNode *> &DiagramLayout::getLinkColumnSortedNodes() const {
    return linkColumnSortedNodes;
}

const std::set<DiagramNode *> &DiagramLayout::getExecColumnSortedNodes() const {
    return execColumnSortedNodes;
}
