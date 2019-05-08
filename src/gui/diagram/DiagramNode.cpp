//
// Created by MOmac on 09.03.2019.
//

#include "gui/diagram/DiagramNode.h"
#include "gui/diagram/DiagramScene.h"

DiagramNode::DiagramNode(DiagramScene *diagram) : QObject () {
    this->diagram = diagram;
    this->colspan = 1;
    this->column = 0;
    this->viewSide = LEFT;

    connect(this, &DiagramNode::nodeRectChanged, this, &DiagramNode::onNodeRectChanged);
}

DiagramNode::~DiagramNode() {
    for (const auto& nameConnPointPair : connectionPoints)
        delete nameConnPointPair.second;
}

void DiagramNode::paint(QPainter *painter) const {
    painter->setClipRect(nodeRect.adjusted(0, 0, 1, 1));
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

const map<QString, ConnectionPoint*> &DiagramNode::getConnectionPoints() const {
    return connectionPoints;
}

map<QString, ConnectionPoint*> &DiagramNode::getConnectionPoints() {
    return connectionPoints;
}

void DiagramNode::onNodeRectChanged() {
    if (viewSide == DiagramNode::RIGHT)
        nodeBindable = nodeRect.topRight();
    else
        nodeBindable = nodeRect.topLeft();

    QPoint leftPoint{nodeRect.left() + 15, nodeRect.bottom() - 15};
    QPoint rightPoint{nodeRect.right() - 15, nodeRect.bottom() - 15};

    int leftIdx = 0;
    int rightIdx = 0;

    for (auto &nameConnPointPair : connectionPoints) {
        if (nameConnPointPair.second->getSide() == Side::LEFT) {
            nameConnPointPair.second->set(leftPoint + QPoint(0, - leftIdx * CONN_POINT_GAP));
            leftIdx++;
        } else {
            nameConnPointPair.second->set(rightPoint + QPoint(0, - rightIdx * CONN_POINT_GAP));
            rightIdx++;
        }
    }
}

Bindable<QPoint> & DiagramNode::getNodeBindable() {
    return nodeBindable;
}

void DiagramNode::registerConnectionPoint(ConnectionPoint *connectionPoint) {
    connectionPoints[connectionPoint->getName()] = connectionPoint;
    connect(connectionPoint, &ConnectionPoint::clicked, diagram, &DiagramScene::scrollTo);
    connect(connectionPoint, &ConnectionPoint::repaintRequested, diagram, &DiagramScene::repaint);
    this->addHoverableChild(connectionPoint);
}

void DiagramNode::paintConnectionPoints(QPainter *painter) const {
    for (const auto& nameConnPointPair : connectionPoints) {
        nameConnPointPair.second->paint(painter);
    }
}

void DiagramNode::hoverEnteredEvent(QHoverEvent *event) {
    emit hoverEntered();
    emit diagram->pushNodeToFront(this);
    event->accept();
    Hoverable::hoverEnteredEvent(event);
}

void DiagramNode::hoverLeavedEvent() {
    emit hoverLeaved();
    Hoverable::hoverLeavedEvent();
}

void DiagramNode::mousePressEvent(QMouseEvent *event) {
    IMouseListener::mousePressEvent(event);

    for (auto nameConnPointPair : connectionPoints) {
        if (nameConnPointPair.second->contains(event->pos()))
            nameConnPointPair.second->mousePressEvent(event);
    }
}

void DiagramNode::mouseReleaseEvent(QMouseEvent *event) {
    IMouseListener::mouseReleaseEvent(event);

    for (auto nameConnPointPair : connectionPoints) {
        if (nameConnPointPair.second->contains(event->pos()))
            nameConnPointPair.second->mouseReleaseEvent(event);
    }
}

DiagramNode::ViewSide DiagramNode::getViewSide() const {
    return viewSide;
}
