//
// Created by MOmac on 17.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERMODELITEM_H
#define PROJECTELF_ELFPROGRAMHEADERMODELITEM_H

#include "core/models/ELFIndexedModelItem.h"
#include "core/models/ELFSegmentModelItem.h"
#include "core/models/ModelHelpers.h"

class ELFProgramHeaderModelItem : public ELFIndexedModelItem {
    Q_OBJECT

    HEX_ELF_PROP_DECL(type, Type)
    HEX_ELF_PROP_DECL(flags, Flags)
    HEX_ELF_PROP_DECL(offset, Offset)
    HEX_ELF_PROP_DECL(vaddr, Vaddr)
    HEX_ELF_PROP_DECL(paddr, Paddr)
    HEX_ELF_PROP_DECL(filesz, Filesz)
    HEX_ELF_PROP_DECL(memsz, Memsz)
    HEX_ELF_PROP_DECL(align, Align)
public:
    ELFProgramHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index);

    ~ELFProgramHeaderModelItem() override;

    bool isValid() const override;

    ELFSegmentModelItem *getSegmentModelItem() const;

protected:
    void onStructureChanged() final;

private:
    ELFSegmentModelItem *segmentModelItem;

};

#endif //PROJECTELF_ELFPROGRAMHEADERMODELITEM_H
