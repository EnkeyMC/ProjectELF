//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERTABLE_H
#define PROJECTELF_ELFPROGRAMHEADERTABLE_H

#include <vector>
#include <ELFHeader.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFProgramHeaderModelItem.h"

class ELFProgramHeaderTableModelItem : public ELFModelItem {
public:
    explicit ELFProgramHeaderTableModelItem(ELFModel *parent, elf::ELFHeader *header);

    virtual ~ELFProgramHeaderTableModelItem();

private:
    elf::ELFHeader *header;

    std::vector<ELFProgramHeaderModelItem *> programHeaderModelItems;
};


#endif //PROJECTELF_ELFPROGRAMHEADERTABLE_H
