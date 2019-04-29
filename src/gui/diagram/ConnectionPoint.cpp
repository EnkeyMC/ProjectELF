//
// Created by MOmac on 25.04.2019.
//

#include "gui/diagram/ConnectionPoint.h"

ConnectionPoint::ConnectionPoint(const QString &name, Side side, elf::Elf64_Addr endAddress)
    : name(name), side(side), endAddress(endAddress)
{

}

void ConnectionPoint::paint(QPainter *painter) const {
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);

    if (hovered) {
        QPainterPath trianglePath;
        if (side == LEFT) {
            trianglePath.moveTo(get() + QPoint(-RADIUS, 0));
            trianglePath.lineTo(get() + QPoint(RADIUS, -RADIUS));
            trianglePath.lineTo(get() + QPoint(RADIUS, RADIUS));
            trianglePath.lineTo(get() + QPoint(-RADIUS, 0));
        } else {
            trianglePath.moveTo(get() + QPoint(RADIUS, 0));
            trianglePath.lineTo(get() + QPoint(-RADIUS, -RADIUS));
            trianglePath.lineTo(get() + QPoint(-RADIUS, RADIUS));
            trianglePath.lineTo(get() + QPoint(RADIUS, 0));
        }

        painter->fillPath(trianglePath, painter->brush());
    } else {
        painter->drawEllipse(this->get(), RADIUS, RADIUS);
    }


    if (side == LEFT) {
        auto rect = QRect(get() + QPoint(RADIUS + GAP, - RADIUS - PADDING), QSize(200, 2*(RADIUS + PADDING)));
        painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, getName());
    } else {
        auto rect = QRect(get() - QPoint(RADIUS + GAP + 200, RADIUS + PADDING), QSize(200, 2*(RADIUS + PADDING)));
        painter->drawText(rect, Qt::AlignRight | Qt::AlignVCenter, getName());
    }
}

const QString &ConnectionPoint::getName() const {
    return name;
}

Side ConnectionPoint::getSide() const {
    return side;
}

int ConnectionPoint::getEndAddress() const {
    return endAddress;
}

bool ConnectionPoint::contains(const QPoint &point) const {
    QRect rect{get().x() - RADIUS, get().y() - RADIUS, 2*RADIUS, 2*RADIUS};
    return rect.contains(point);
}

void ConnectionPoint::mousePressEvent(QMouseEvent *event) {
    IMouseListener::mousePressEvent(event);

    emit clicked(endAddress);
}

void ConnectionPoint::hoverEnteredEvent(QHoverEvent *event) {
    Hoverable::hoverEnteredEvent(event);
    emit repaintRequested();
}

void ConnectionPoint::hoverLeavedEvent() {
    Hoverable::hoverLeavedEvent();
    emit repaintRequested();
}
