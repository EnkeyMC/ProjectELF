//
// Created by MOmac on 25.04.2019.
//

#include "gui/diagram/Connection.h"
#include "gui/diagram/DiagramScene.h"

Connection::Connection(DiagramScene* diagram, Connection::Side side, int level)
    : diagram(diagram), side(side), visible(false), level(level)
{

}

void Connection::paint(QPainter *painter) const {
    if (!visible)
        return;

    int lineX = -diagram->getLayout()->getArrowSpace() / 2 + 5*level;
    if (side == RIGHT) {
        lineX = diagram->getLayout()->getContentWidth() - lineX;
    }

    const auto startPoint = startBindable.get();
    const auto endPoint = endBindable.get();

    painter->setClipping(false);
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
    painter->setClipping(true);
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
