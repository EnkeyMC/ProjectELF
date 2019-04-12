//
// Created by MOmac on 09.03.2019.
//

#include <include/gui/diagram/DiagramNode.h>

#include "gui/diagram/DiagramNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramNode::DiagramNode(DiagramScene *diagram) {
    this->diagram = diagram;
    this->colspan = 1;
}

DiagramNode::~DiagramNode() = default;

int DiagramNode::getColspan() const {
    return colspan;
}

bool DiagramNode::operator<(const DiagramNode &rhs) const {
    return this->getProportionalPosition() < rhs.getProportionalPosition();
}

const QRect &DiagramNode::getNodeRect() const {
    return nodeRect;
}

void DiagramNode::setNodeRect(const QRect &nodeRect) {
    this->nodeRect = nodeRect;
    emit nodeRectChanged(this->nodeRect);
}

void DiagramNode::setHeight(int height) {
    this->nodeRect.setHeight(height);
    emit nodeRectChanged(this->nodeRect);
}

void DiagramNode::moveTop(int y) {
    this->nodeRect.moveTop(y);
    emit nodeRectChanged(this->nodeRect);
}

void DiagramNode::setBottom(int y) {
    this->nodeRect.setBottom(y);
    emit nodeRectChanged(this->nodeRect);
}

void DiagramNode::stretch(double factor) {
    this->nodeRect.setTop(static_cast<int>(this->nodeRect.top() * factor));
    this->nodeRect.setBottom(static_cast<int>(this->nodeRect.bottom() * factor));
    emit nodeRectChanged(this->nodeRect);
}

void DiagramNode::setColumn(int column) {
    this->column = column;
}

int DiagramNode::getColumn() const {
    return column;
}
