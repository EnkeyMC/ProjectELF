//
// Created by MOmac on 03.05.2019.
//

#include "core/models/ELFSectionHeaderListModel.h"

ELFSectionHeaderListModel::ELFSectionHeaderListModel(QObject *parent) : ListModelBase(parent) {

}

ELFSectionHeaderListModel::~ELFSectionHeaderListModel() {
    for (auto sectionHeaderModelItem : this->sectionHeaderModelItems)
        delete sectionHeaderModelItem;
}

int ELFSectionHeaderListModel::rowCount(const QModelIndex &parent) const {
    return sectionHeaderModelItems.size();
}

QVariant ELFSectionHeaderListModel::getData(int idx, int role) const {
    switch (role) {
        case SectionHeaderModelRole:
            return QVariant::fromValue(sectionHeaderModelItems.at(idx));
        default:
            return QVariant();
    }
}

const vector<ELFSectionHeaderModelItem *> &ELFSectionHeaderListModel::getSectionHeaderModelItems() const {
    return sectionHeaderModelItems;
}

void ELFSectionHeaderListModel::add(ELFSectionHeaderModelItem *modelItem) {
    emit beginInsertRows(QModelIndex(), sectionHeaderModelItems.size(), sectionHeaderModelItems.size());
    sectionHeaderModelItems.push_back(modelItem);
    emit endInsertRows();
}

QHash<int, QByteArray> ELFSectionHeaderListModel::roleNames() const {
    QHash<int, QByteArray> names;
    names[SectionHeaderModelRole] = "sectionHeaderModel";
    return names;
}
