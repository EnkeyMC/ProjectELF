//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H
#define PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H

#include <vector>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSectionHeaderModelItem.h"

class ELFSectionHeaderTableModelItem : public ELFModelItem {
public:
    explicit ELFSectionHeaderTableModelItem(ELFModel *parent);

    virtual ~ELFSectionHeaderTableModelItem();

private:
    std::vector<ELFSectionHeaderModelItem *> sectionHeaderModelItems;
};


#endif //PROJECTELF_ELFSECTIONHEADERTABLEMODELITEM_H
