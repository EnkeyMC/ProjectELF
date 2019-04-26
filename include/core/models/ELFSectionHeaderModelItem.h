//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERMODELITEM_H
#define PROJECTELF_ELFSECTIONHEADERMODELITEM_H

#include <ELF.h>

#include "core/models/ELFIndexedModelItem.h"
#include "core/models/ELFSectionModelItem.h"

class ELFSectionHeaderModelItem : public ELFIndexedModelItem {
public:
    explicit ELFSectionHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index);

    virtual ~ELFSectionHeaderModelItem();

    ELFSectionModelItem *getSectionModelItem() const;

protected:

    ELFSectionModelItem *sectionModelItem;

};


#endif //PROJECTELF_ELFSECTIONHEADERMODELITEM_H
