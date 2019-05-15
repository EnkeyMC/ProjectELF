//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H
#define PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H

#include <vector>
#include <ELF.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSectionHeaderListModel.h"

class ELFSectionHeaderTableModelItem : public ELFModelItem {
    Q_OBJECT

    Q_PROPERTY(ELFSectionHeaderListModel *sectionHeaderListModel READ getListModel NOTIFY listModelChanged)
public:
    explicit ELFSectionHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf);

    ~ELFSectionHeaderTableModelItem() override;

    const std::vector<ELFSectionHeaderModelItem *> &getSectionHeaders() const;

    ELFSectionHeaderListModel *getListModel() const;

    bool isValid() const override;

signals:
    void listModelChanged();

protected:
    void onStructureChanged() final;

private:
    ELFSectionHeaderListModel *listModel;
};


#endif //PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H
