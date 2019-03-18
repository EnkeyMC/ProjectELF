//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERTABLE_H
#define PROJECTELF_ELFPROGRAMHEADERTABLE_H

#include <vector>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFProgramHeaderModelItem.h"

class ELFProgramHeaderTableModelItem : public ELFModelItem {
public:
    explicit ELFProgramHeaderTableModelItem(ELFModel *parent);

    virtual ~ELFProgramHeaderTableModelItem();

private:
    std::vector<ELFProgramHeaderModelItem *> programHeaderModelItems;
};


#endif //PROJECTELF_ELFPROGRAMHEADERTABLE_H
