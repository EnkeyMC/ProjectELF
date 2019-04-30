//
// Created by MOmac on 30.04.2019.
//

#ifndef PROJECTELF_ELFISSUELISTMODEL_H
#define PROJECTELF_ELFISSUELISTMODEL_H

#include <ELFIssuesBySeverity.h>

#include "core/models/ListModelBase.h"

class ELFIssueListModel : public ListModelBase {
    Q_OBJECT
public:
    enum {
        DescriptionRole = Qt::UserRole + 1,
        SeverityRole,
        SourceRole,
        TypeRole,
        SourceIndexRole
    };

    explicit ELFIssueListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;

    ELFIssueListModel &operator=(const elf::ELFIssuesBySeverity &issues);

    QHash<int, QByteArray> roleNames() const override;

protected:
    QVariant getData(int idx, int role) const override;

private:
    elf::ELFIssuesBySeverity issues;
};


#endif //PROJECTELF_ELFISSUELISTMODEL_H
