//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERMODELITEM_H
#define PROJECTELF_ELFPROGRAMHEADERMODELITEM_H

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSegmentModelItem.h"

class ELFProgramHeaderModelItem : public ELFModelItem {
public:
    explicit ELFProgramHeaderModelItem(ELFModel *parent);

    virtual ~ELFProgramHeaderModelItem();

private:
    ELFSegmentModelItem *segmentModelItem;

};


#endif //PROJECTELF_ELFPROGRAMHEADERMODELITEM_H
