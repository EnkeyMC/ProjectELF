//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERMODELITEM_H
#define PROJECTELF_ELFPROGRAMHEADERMODELITEM_H

#include "core/models/ELFIndexedModelItem.h"
#include "core/models/ELFSegmentModelItem.h"

class ELFProgramHeaderModelItem : public ELFIndexedModelItem {
public:
    explicit ELFProgramHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index);

    virtual ~ELFProgramHeaderModelItem();

    ELFSegmentModelItem *getSegmentModelItem() const;

private:
    ELFSegmentModelItem *segmentModelItem;

};


#endif //PROJECTELF_ELFPROGRAMHEADERMODELITEM_H
