//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERMODELITEM_H
#define PROJECTELF_ELFSECTIONHEADERMODELITEM_H

#include <ELFSectionHeader.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSectionModelItem.h"

class ELFSectionHeaderModelItem : public ELFModelItem {
public:
    explicit ELFSectionHeaderModelItem(ELFModel *parent, elf::ELFSectionHeader *sectionHeader);

    virtual ~ELFSectionHeaderModelItem();

protected:
    elf::ELFSectionHeader *sectionHeader;
    ELFSectionModelItem *sectionModelItem;

};


#endif //PROJECTELF_ELFSECTIONHEADERMODELITEM_H
