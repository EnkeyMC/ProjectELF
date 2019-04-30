//
// Created by MOmac on 30.04.2019.
//

#include "core/models/ELFIssueListModel.h"
#include "core/ELFIssueConverter.h"

ELFIssueListModel::ELFIssueListModel(QObject *parent) : ListModelBase(parent) {

}

int ELFIssueListModel::rowCount(const QModelIndex &parent) const {
    return issues.get_issues().size();
}

QVariant ELFIssueListModel::getData(int idx, int role) const {
    auto issue = issues.get_issues()[idx];
    switch (role) {
    case DescriptionRole:
        return QVariant(ELFIssueConverter::toReadable(issue));
    case SeverityRole:
        return QVariant(issue.get_severity());
    case SourceRole:
        return QVariant(issue.get_source());
    case TypeRole:
        return QVariant(issue.get_type());
    case SourceIndexRole:
        return QVariant(issue.get_index());
    default:
        return QVariant();
    }
}

ELFIssueListModel &ELFIssueListModel::operator=(const elf::ELFIssuesBySeverity &issues) {
    if (this->issues.get_issues().size() > 0) {
        emit beginRemoveRows(QModelIndex(), 0, this->issues.get_issues().size() - 1);
        this->issues.clear();
        emit endRemoveRows();
    }

    if (issues.get_issues().size() > 0) {
        emit beginInsertRows(QModelIndex(), 0, issues.get_issues().size() - 1);
        this->issues = issues;
        emit endInsertRows();
    }

    return *this;
}

QHash<int, QByteArray> ELFIssueListModel::roleNames() const {
    QHash<int, QByteArray> names;
    names[DescriptionRole] = "description";
    names[SeverityRole] = "severity";
    names[SourceRole] = "source";
    names[TypeRole] = "type";
    names[SourceIndexRole] = "sourceIndex";
    return names;
}
