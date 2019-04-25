//
// Created by MOmac on 16.04.2019.
//

#ifndef PROJECTELF_IMOUSELISTENER_H
#define PROJECTELF_IMOUSELISTENER_H


#include <QMouseEvent>
#include <QHoverEvent>

class IMouseListener {
public:
    virtual void mousePressEvent(QMouseEvent *event) {}

    virtual void mouseReleaseEvent(QMouseEvent *event) {}

    virtual void hoverMoveEvent(QHoverEvent *event) {}

    virtual void hoverEnteredEvent(QHoverEvent *event) {}

    virtual void hoverLeavedEvent(QHoverEvent *event) {}
};


#endif //PROJECTELF_IMOUSELISTENER_H
