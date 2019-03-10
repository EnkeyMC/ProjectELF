//
// Created by MOmac on 10.03.2019.
//

#include "gui/diagram/CondensedDiagramLayout.h"
#include "gui/diagram/DiagramLayout.h"
#include "gui/diagram/DiagramScene.h"

DiagramLayout::DiagramLayout(DiagramScene *diagram) : QObject(diagram) {
    this->diagram = diagram;
}

void DiagramLayout::addLinkNode(DiagramNode *node) {
    this->m_linkColumnSortedNodes.insert(node);
}

void DiagramLayout::addExecNode(DiagramNode *node) {
    this->m_execColumnSortedNodes.insert(node);
}