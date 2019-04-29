//
// Created by MOmac on 25.04.2019.
//

#ifndef PROJECTELF_CONNECTIONPOINT_H
#define PROJECTELF_CONNECTIONPOINT_H

#include <QString>
#include <QPainter>
#include <ELFTypes.h>

#include "core/Bindable.h"
#include "core/Hoverable.h"
#include "core/IMouseListener.h"
#include "core/Side.h"

class ConnectionPoint : public QObject, public Bindable<QPoint>, public Hoverable, public IMouseListener {
    Q_OBJECT
public:

    static const elf::Elf64_Addr INVALID_ADDRESS = -1;

    explicit ConnectionPoint(const QString &name = "", Side side = LEFT, elf::Elf64_Addr endAddress = INVALID_ADDRESS);

    void paint(QPainter *painter) const;

    const QString &getName() const;

    Side getSide() const;

    int getEndAddress() const;

    bool contains(const QPoint &point) const override;

    void mousePressEvent(QMouseEvent *event) override;

signals:
    void clicked(elf::Elf64_Addr address);

    void repaintRequested();

protected:
    void hoverEnteredEvent(QHoverEvent *event) override;

    void hoverLeavedEvent() override;

private:
    static const int RADIUS = 5;
    static const int GAP = 10;
    static const int PADDING = 3;

    Side side;
    QString name;
    elf::Elf64_Addr endAddress;
};


#endif //PROJECTELF_CONNECTIONPOINT_H
