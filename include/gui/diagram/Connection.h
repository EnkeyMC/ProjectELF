//
// Created by MOmac on 25.04.2019.
//

#ifndef PROJECTELF_CONNECTION_H
#define PROJECTELF_CONNECTION_H

#include <QObject>
#include <QPoint>
#include <QPainter>
#include "core/Bindable.h"

class DiagramScene;

class Connection : public QObject {
    Q_OBJECT
public:
    enum Side {
        LEFT,
        RIGHT
    };

    explicit Connection(DiagramScene* diagram, enum Side side);

    void paint(QPainter *painter) const;

    Bindable<QPoint> &getStartBindable();

    Bindable<QPoint> &getEndBindable();

public slots:
    void setVisible();
    void setInvisible();

private:
    Bindable<QPoint> startBindable;
    Bindable<QPoint> endBindable;

    DiagramScene* diagram;

    enum Side side;
    bool visible;
};


#endif //PROJECTELF_CONNECTION_H
