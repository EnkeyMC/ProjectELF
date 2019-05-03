//
// Created by MOmac on 03.05.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERLISTMODEL_H
#define PROJECTELF_ELFSECTIONHEADERLISTMODEL_H

#include "core/models/ListModelBase.h"
#include "core/models/ELFSectionHeaderModelItem.h"

class ELFSectionHeaderListModel : public ListModelBase {
public:
    enum {
        SectionHeaderModelRole = Qt::UserRole + 1
    };

    explicit ELFSectionHeaderListModel(QObject *parent = nullptr);

    virtual ~ELFSectionHeaderListModel();

    int rowCount(const QModelIndex &parent) const override;

    const vector<ELFSectionHeaderModelItem *> &getSectionHeaderModelItems() const;

    void add(ELFSectionHeaderModelItem *modelItem);

    QHash<int, QByteArray> roleNames() const override;

protected:
    QVariant getData(int idx, int role) const override;

private:
    std::vector<ELFSectionHeaderModelItem *> sectionHeaderModelItems;
};


#endif //PROJECTELF_ELFSECTIONHEADERLISTMODEL_H
