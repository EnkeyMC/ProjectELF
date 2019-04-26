//
// Created by MOmac on 09.03.2019.
//

#include "gui/diagram/DiagramNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramNode::DiagramNode(DiagramScene *diagram) : QObject (), column(0) {
    this->diagram = diagram;
    this->colspan = 1;

    connect(this, &DiagramNode::nodeRectChanged, this, &DiagramNode::onNodeRectChanged);
}

DiagramNode::~DiagramNode() = default;

void DiagramNode::paint(QPainter *painter) const {
    painter->setClipRect(nodeRect);
}

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

QRect DiagramNode::getBounds() const {
    return nodeRect;
}

bool DiagramNode::contains(const QPoint &point) const {
    return nodeRect.contains(point);
}

const map<QString, ConnectionPoint> &DiagramNode::getConnectionPoints() const {
    return connectionPoints;
}

map<QString, ConnectionPoint> &DiagramNode::getConnectionPoints() {
    return connectionPoints;
}

void DiagramNode::onNodeRectChanged() {
    if (column == 0)
        nodeBindable = nodeRect.topLeft();
    else
        nodeBindable = nodeRect.topRight();

    QPoint leftPoint{nodeRect.left() + 15, nodeRect.bottom() - 15};
    QPoint rightPoint{nodeRect.right() - 15, nodeRect.bottom() - 15};

    int leftIdx = 0;
    int rightIdx = 0;

    for (auto &nameConnPointPair : connectionPoints) {
        if (nameConnPointPair.second.getSide() == ConnectionPoint::LEFT) {
            nameConnPointPair.second.set(leftPoint + QPoint(0, - leftIdx * CONN_POINT_GAP));
            leftIdx++;
        } else {
            nameConnPointPair.second.set(rightPoint + QPoint(0, - rightIdx * CONN_POINT_GAP));
            rightIdx++;
        }
    }
}

Bindable<QPoint> & DiagramNode::getNodeBindable() {
    return nodeBindable;
}

void DiagramNode::registerConnectionPoint(const ConnectionPoint &connectionPoint) {
    connectionPoints[connectionPoint.getName()] = connectionPoint;
}

void DiagramNode::paintConnectionPoints(QPainter *painter) const {
    for (const auto& nameConnPointPair : connectionPoints) {
        nameConnPointPair.second.paint(painter);
    }
}

void DiagramNode::hoverEnteredEvent() {
    emit hoverEntered();
    Hoverable::hoverEnteredEvent();
}

void DiagramNode::hoverLeavedEvent() {
    emit hoverLeaved();
    Hoverable::hoverLeavedEvent();
}
