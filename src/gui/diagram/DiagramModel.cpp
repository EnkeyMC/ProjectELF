//
// Created by MOmac on 07.03.2019.
//

#include "gui/diagram/DiagramModel.h"

DiagramModel::DiagramModel(QObject *parent) : QObject(parent) {
    this->addItem(new DiagramModelItem(this));
}

DiagramModel::~DiagramModel() {
    for (auto item : items)
        delete item;
}

void DiagramModel::addItem(DiagramModelItem *item) {
    items.push_back(item);
}

const std::vector<DiagramModelItem *> &DiagramModel::getItems() const {
    return this->items;
}
