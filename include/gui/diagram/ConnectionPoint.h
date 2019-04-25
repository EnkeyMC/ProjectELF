//
// Created by MOmac on 25.04.2019.
//

#ifndef PROJECTELF_CONNECTIONPOINT_H
#define PROJECTELF_CONNECTIONPOINT_H

#include <QString>
#include <QPainter>

#include "core/Bindable.h"

class ConnectionPoint : public Bindable<QPoint> {
public:
    enum Side {
        LEFT,
        RIGHT
    };

    explicit ConnectionPoint(const QString &name = "", enum Side side = LEFT);

    void paint(QPainter *painter) const;

    const QString &getName() const;

    Side getSide() const;

private:
    static const int RADIUS = 5;
    static const int GAP = 10;
    static const int PADDING = 3;

    enum Side side;
    QString name;

};


#endif //PROJECTELF_CONNECTIONPOINT_H
