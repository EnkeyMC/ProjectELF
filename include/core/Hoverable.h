//
// Created by MOmac on 26.04.2019.
//

#ifndef PROJECTELF_HOVERABLE_H
#define PROJECTELF_HOVERABLE_H

#include <QHoverEvent>
#include <vector>

#include "core/IContains.h"

class Hoverable : virtual public IContains {
public:
    Hoverable();

    void hoverMoveEvent(QHoverEvent *event);

protected:
    void addHoverableChild(Hoverable *hoverable);

    virtual void hoverEnteredEvent();

    virtual void hoverLeavedEvent();

    bool hovered;

private:
    std::vector<Hoverable *> hoverableChildren;
};


#endif //PROJECTELF_HOVERABLE_H
