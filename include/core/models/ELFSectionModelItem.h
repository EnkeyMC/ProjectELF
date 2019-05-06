//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONMODELITEM_H
#define PROJECTELF_ELFSECTIONMODELITEM_H

#include <ELF.h>

#include "core/models/ELFIndexedModelItem.h"

class ELFSectionModelItem : public ELFIndexedModelItem {
public:
    ELFSectionModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index);

    bool isValid() const override;
};


#endif //PROJECTELF_ELFSECTIONMODELITEM_H
