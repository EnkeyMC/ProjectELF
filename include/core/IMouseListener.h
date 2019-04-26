//
// Created by MOmac on 16.04.2019.
//

#ifndef PROJECTELF_IMOUSELISTENER_H
#define PROJECTELF_IMOUSELISTENER_H


#include <QMouseEvent>

class IMouseListener {
public:
    virtual void mousePressEvent(QMouseEvent *event) {}

    virtual void mouseReleaseEvent(QMouseEvent *event) {}
};


#endif //PROJECTELF_IMOUSELISTENER_H
