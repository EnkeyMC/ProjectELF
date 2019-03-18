//
// Created by MOmac on 15.03.2019.
//

#ifndef PROJECTELF_DIAGRAMHEADERMODELITEM_H
#define PROJECTELF_DIAGRAMHEADERMODELITEM_H

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"

class ELFHeaderModelItem : public ELFModelItem {
public:
    explicit ELFHeaderModelItem(ELFModel *parent);

    ~ELFHeaderModelItem() override;

private:
    ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem;
    ELFProgramHeaderTableModelItem *programHeaderTableModelItem;
};


#endif //PROJECTELF_DIAGRAMHEADERMODELITEM_H
