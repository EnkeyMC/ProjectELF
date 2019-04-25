//
// Created by MOmac on 25.04.2019.
//

#include "gui/diagram/ConnectionPoint.h"

ConnectionPoint::ConnectionPoint(const QString &name, enum Side side)
    : name(name), side(side)
{

}

void ConnectionPoint::paint(QPainter *painter) const {
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawEllipse(this->get(), RADIUS, RADIUS);

    if (side == LEFT) {
        auto topLeft = QRect(get() + QPoint(RADIUS + GAP, - RADIUS - PADDING), QSize(200, 2*(RADIUS + PADDING)));
        painter->drawText(topLeft, Qt::AlignLeft | Qt::AlignVCenter, getName());
    } else {
        auto topLeft = QRect(get() - QPoint(RADIUS + GAP + 200, RADIUS + PADDING), QSize(200, 2*(RADIUS + PADDING)));
        painter->drawText(topLeft, Qt::AlignRight | Qt::AlignVCenter, getName());
    }
}

const QString &ConnectionPoint::getName() const {
    return name;
}

ConnectionPoint::Side ConnectionPoint::getSide() const {
    return side;
}
