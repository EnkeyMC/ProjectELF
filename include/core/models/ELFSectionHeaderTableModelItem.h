//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H
#define PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H

#include <vector>
#include <ELF.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSectionHeaderModelItem.h"

class ELFSectionHeaderTableModelItem : public ELFModelItem {
public:
    explicit ELFSectionHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf);

    virtual ~ELFSectionHeaderTableModelItem();

    const std::vector<ELFSectionHeaderModelItem *> &getSectionHeaders() const;

private:

    std::vector<ELFSectionHeaderModelItem *> sectionHeaderModelItems;
};


#endif //PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H
