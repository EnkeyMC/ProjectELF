//
// Created by MOmac on 10.03.2019.
//

#include <include/gui/diagram/DiagramLayout.h>

#include "gui/diagram/CondensedDiagramLayout.h"
#include "gui/diagram/DiagramLayout.h"
#include "gui/diagram/DiagramScene.h"

DiagramLayout::DiagramLayout(DiagramScene *diagram) : QObject(diagram) {
    this->diagram = diagram;
}

void DiagramLayout::addLinkNode(DiagramNode *node) {
    this->m_linkColumnSortedNodes.insert(node);
    node->setColumn(0);
}

void DiagramLayout::addExecNode(DiagramNode *node) {
    this->m_execColumnSortedNodes.insert(node);
    node->setColumn(1);
}

void DiagramLayout::forEachLinkNode(const NodeCallback &callback) {
    for (auto node : m_linkColumnSortedNodes)
        callback(*node);
}

void DiagramLayout::forEachExecNode(const NodeCallback &callback) {
    for (auto node : m_execColumnSortedNodes)
        callback(*node);
}

void DiagramLayout::forEachNode(const NodeCallback &callback) {
    forEachLinkNode(callback);
    forEachExecNode(callback);
}
