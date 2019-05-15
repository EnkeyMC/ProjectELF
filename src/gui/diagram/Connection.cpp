//
// Created by MOmac on 25.04.2019.
//

#include "gui/diagram/Connection.h"
#include "gui/diagram/DiagramScene.h"

Connection::Connection(DiagramScene* diagram, Side side, int level)
    : diagram(diagram), side(side), visible(false), level(level), valid(true)
{

}

void Connection::paint(QPainter *painter) const {
    if (!visible)
        return;

    int lineX = -diagram->getLayout()->getArrowSpace() / 2 + 5*level;
    if (side == RIGHT) {
        lineX = diagram->getLayout()->getContentWidth() - lineX;
    }

    painter->setClipping(false);

    if (valid)
        paintValid(painter, lineX);
    else
        paintInvalid(painter, lineX);

    painter->setClipping(true);
}

void Connection::paintInvalid(QPainter *painter, int lineX) const {
    const auto startPoint = startBindable.get();

    painter->setPen(QPen(QColor(0, 0, 0), 2));
    painter->setBrush(Qt::black);

    painter->drawLine(lineX, startPoint.y(), startPoint.x(), startPoint.y());

    painter->setPen(QPen(QColor(230, 0, 0), 2));
    constexpr int crossSize = 5;
    painter->drawLine(lineX - crossSize, startPoint.y() - crossSize, lineX + crossSize, startPoint.y() + crossSize);
    painter->drawLine(lineX - crossSize, startPoint.y() + crossSize, lineX + crossSize, startPoint.y() - crossSize);
}

void Connection::paintValid(QPainter *painter, int lineX) const {
    const auto startPoint = startBindable.get();
    const auto endPoint = endBindable.get();

    painter->setPen(QPen(QColor(0, 0, 0), 2));
    painter->setBrush(Qt::black);

    painter->drawLine(lineX, startPoint.y(), startPoint.x(), startPoint.y());
    painter->drawLine(lineX, startPoint.y(), lineX, endBindable.get().y());
    painter->drawLine(lineX, endPoint.y(), endPoint.x(), endPoint.y());
    if (side == LEFT) {
        painter->drawLine(endPoint.x() - 5, endPoint.y() - 5, endPoint.x(), endPoint.y());
        painter->drawLine(endPoint.x() - 5, endPoint.y() + 5, endPoint.x(), endPoint.y());
    } else {
        painter->drawLine(endPoint.x() + 5, endPoint.y() - 5, endPoint.x(), endPoint.y());
        painter->drawLine(endPoint.x() + 5, endPoint.y() + 5, endPoint.x(), endPoint.y());
    }
}

Bindable<QPoint> &Connection::getStartBindable() {
    return startBindable;
}

Bindable<QPoint> &Connection::getEndBindable()  {
    return endBindable;
}

void Connection::setVisible() {
    visible = true;
    emit diagram->repaint();
}

void Connection::setInvisible() {
    visible = false;
    emit diagram->repaint();
}

bool Connection::isValid() const {
    return valid;
}

void Connection::setValid(bool valid) {
    this->valid = valid;
}
