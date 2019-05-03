//
// Created by MOmac on 03.05.2019.
//

#include "core/models/ELFProgramHeaderListModel.h"
#include "core/models/ELFProgramHeaderModelItem.h"

ELFProgramHeaderListModel::ELFProgramHeaderListModel(QObject *parent) : ListModelBase(parent) {

}

int ELFProgramHeaderListModel::rowCount(const QModelIndex &parent) const {
    return programHeaderModelItems.size();
}

QVariant ELFProgramHeaderListModel::getData(int idx, int role) const {
    switch (role) {
        case ProgramHeaderModelRole:
            return QVariant::fromValue(programHeaderModelItems.at(idx));
        default:
            return QVariant();
    }
}

const std::vector<ELFProgramHeaderModelItem *> &ELFProgramHeaderListModel::getProgramHeaderModelItems() const {
    return programHeaderModelItems;
}

ELFProgramHeaderListModel::~ELFProgramHeaderListModel() {
    for (auto programHeaderModelItem : this->programHeaderModelItems)
        delete programHeaderModelItem;
}

void ELFProgramHeaderListModel::add(ELFProgramHeaderModelItem *modelItem) {
    emit beginInsertRows(QModelIndex(), programHeaderModelItems.size(), programHeaderModelItems.size());
    programHeaderModelItems.push_back(modelItem);
    emit endInsertRows();
}

QHash<int, QByteArray> ELFProgramHeaderListModel::roleNames() const {
    QHash<int, QByteArray> names;
    names[ProgramHeaderModelRole] = "programHeaderModel";
    return names;
}

