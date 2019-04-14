//
// Created by MOmac on 14.04.2019.
//

#ifndef PROJECTELF_ELFINDEXEDMODELITEM_H
#define PROJECTELF_ELFINDEXEDMODELITEM_H

#include "core/models/ELFModelItem.h"

class ELFIndexedModelItem : public ELFModelItem {
public:
    ELFIndexedModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index);

protected:
    unsigned index;
};


#endif //PROJECTELF_ELFINDEXEDMODELITEM_H
