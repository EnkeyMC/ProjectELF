//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERMODELITEM_H
#define PROJECTELF_ELFSECTIONHEADERMODELITEM_H

#include <ELF.h>

#include "core/models/ELFIndexedModelItem.h"
#include "core/models/ELFSectionModelItem.h"
#include "core/models/ModelHelpers.h"

class ELFSectionHeaderModelItem : public ELFIndexedModelItem {
    Q_OBJECT

    HEX_ELF_PROP_DECL(name, Name)
    HEX_ELF_PROP_DECL(type, Type)
    HEX_ELF_PROP_DECL(flags, Flags)
    HEX_ELF_PROP_DECL(addr, Addr)
    HEX_ELF_PROP_DECL(offset, Offset)
    HEX_ELF_PROP_DECL(size, Size)
    HEX_ELF_PROP_DECL(link, Link)
    HEX_ELF_PROP_DECL(info, Info)
    HEX_ELF_PROP_DECL(addralign, Addralign)
    HEX_ELF_PROP_DECL(entsize, Entsize)
public:
    explicit ELFSectionHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index);

    ~ELFSectionHeaderModelItem() override;

    ELFSectionModelItem *getSectionModelItem() const;

    bool isValid() const override;

protected:
    void onStructureChanged() final;

    ELFSectionModelItem *sectionModelItem;

};


#endif //PROJECTELF_ELFSECTIONHEADERMODELITEM_H
