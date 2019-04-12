//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONMODELITEM_H
#define PROJECTELF_ELFSECTIONMODELITEM_H

#include <ELFSectionHeader.h>

#include "core/models/ELFModelItem.h"

class ELFSectionModelItem : public ELFModelItem {
public:
    ELFSectionModelItem(ELFModel *parent, elf::ELFSectionHeader *sectionHeader);

private:
    elf::ELFSectionHeader *sectionHeader;
};


#endif //PROJECTELF_ELFSECTIONMODELITEM_H
