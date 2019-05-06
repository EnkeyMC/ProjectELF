//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSEGMENTMODELITEM_H
#define PROJECTELF_ELFSEGMENTMODELITEM_H

#include "core/models/ELFIndexedModelItem.h"

class ELFSegmentModelItem : public ELFIndexedModelItem {
public:
    ELFSegmentModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index);

    bool isValid() const override;
};


#endif //PROJECTELF_ELFSEGMENTMODELITEM_H
