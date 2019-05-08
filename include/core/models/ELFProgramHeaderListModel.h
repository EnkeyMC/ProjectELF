//
// Created by MOmac on 03.05.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERLISTMODEL_H
#define PROJECTELF_ELFPROGRAMHEADERLISTMODEL_H

#include "core/models/ListModelBase.h"

class ELFProgramHeaderModelItem;

class ELFProgramHeaderListModel : public ListModelBase {
public:
    enum {
        ProgramHeaderModelRole = Qt::UserRole + 1
    };

    explicit ELFProgramHeaderListModel(QObject *parent = nullptr);

    ~ELFProgramHeaderListModel() override;

    int rowCount(const QModelIndex &parent) const override;

    const std::vector<ELFProgramHeaderModelItem *> &getProgramHeaderModelItems() const;

    void add(ELFProgramHeaderModelItem *modelItem);

    void clear();

    QHash<int, QByteArray> roleNames() const override;

protected:
    QVariant getData(int idx, int role) const override;

private:
    std::vector<ELFProgramHeaderModelItem *> programHeaderModelItems;
};


#endif //PROJECTELF_ELFPROGRAMHEADERLISTMODEL_H
