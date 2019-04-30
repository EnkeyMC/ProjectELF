//
// Created by MOmac on 30.04.2019.
//

#include "core/models/ListModelBase.h"

ListModelBase::ListModelBase(QObject *parent) : QAbstractItemModel(parent) {

}

QModelIndex ListModelBase::index(int row, int column, const QModelIndex &parent) const {
    return createIndex(row, column, nullptr);
}

QModelIndex ListModelBase::parent(const QModelIndex &child) const {
    return QModelIndex();
}

int ListModelBase::columnCount(const QModelIndex &parent) const {
    return 0;
}

QVariant ListModelBase::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    return this->getData(index.row(), role);
}
