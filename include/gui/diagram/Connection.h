//
// Created by MOmac on 25.04.2019.
//

#ifndef PROJECTELF_CONNECTION_H
#define PROJECTELF_CONNECTION_H

#include <QObject>
#include <QPoint>
#include <QPainter>
#include "core/Bindable.h"
#include "core/Side.h"

class DiagramScene;

class Connection : public QObject {
    Q_OBJECT
public:

    explicit Connection(DiagramScene* diagram, Side side, int level = 0);

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

    Side side;
    bool visible;
    int level;
};


#endif //PROJECTELF_CONNECTION_H
