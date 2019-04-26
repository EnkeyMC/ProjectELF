//
// Created by MOmac on 26.04.2019.
//

#include "core/Hoverable.h"

Hoverable::Hoverable() : hovered(false) {

}

void Hoverable::hoverMoveEvent(QHoverEvent *event) {
    if (this->contains(event->pos())) {
        if (!hovered) {
            hovered = true;
            hoverEnteredEvent();
        }
    } else {
        if (hovered) {
            hovered = false;
            hoverLeavedEvent();
        }
    }

    for (auto child : hoverableChildren)
        child->hoverMoveEvent(event);
}

void Hoverable::addHoverableChild(Hoverable *hoverable) {
    hoverableChildren.push_back(hoverable);
}

void Hoverable::hoverEnteredEvent() {
}

void Hoverable::hoverLeavedEvent() {
}
