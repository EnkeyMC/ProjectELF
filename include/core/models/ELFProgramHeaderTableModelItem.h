//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERTABLE_H
#define PROJECTELF_ELFPROGRAMHEADERTABLE_H

#include <vector>
#include <ELF.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFProgramHeaderModelItem.h"
#include "core/models/ELFProgramHeaderListModel.h"

class ELFProgramHeaderTableModelItem : public ELFModelItem {
    Q_OBJECT

    Q_PROPERTY(ELFProgramHeaderListModel *programHeaderListModel READ getListModel NOTIFY listModelChanged)
public:
    explicit ELFProgramHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf);

    ~ELFProgramHeaderTableModelItem() override;

    const std::vector<ELFProgramHeaderModelItem *> &getProgramHeaders() const;

    ELFProgramHeaderListModel *getListModel() const;

signals:
    void listModelChanged();

private:
    ELFProgramHeaderListModel *listModel;
};


#endif //PROJECTELF_ELFPROGRAMHEADERTABLE_H
