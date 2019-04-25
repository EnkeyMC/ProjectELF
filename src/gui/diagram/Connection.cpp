//
// Created by MOmac on 25.04.2019.
//

#include "gui/diagram/Connection.h"

Connection::Connection(Connection::Side side) : side(side), visible(false) {

}

void Connection::paint(QPainter *painter) const {
    if (!visible)
        return;
}

Bindable<QPoint> &Connection::getStartBindable() {
    return startBindable;
}

Bindable<QPoint> &Connection::getEndBindable()  {
    return endBindable;
}

void Connection::setVisible() {
    visible = true;
}

void Connection::setInvisible() {
    visible = false;
}
