//
// Created by MOmac on 30.04.2019.
//

#ifndef PROJECTELF_LISTMODELBASE_H
#define PROJECTELF_LISTMODELBASE_H

#include <QAbstractItemModel>

class ListModelBase : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit ListModelBase(QObject *parent = nullptr);

    QModelIndex index(int row, int column, const QModelIndex &parent) const final;

    QModelIndex parent(const QModelIndex &child) const final;

    int columnCount(const QModelIndex &parent) const final;

    QVariant data(const QModelIndex &index, int role) const final;

protected:
    virtual QVariant getData(int idx, int role) const = 0;
};


#endif //PROJECTELF_LISTMODELBASE_H
