//
// Created by MOmac on 15.03.2019.
//

#ifndef PROJECTELF_DIAGRAMHEADERMODELITEM_H
#define PROJECTELF_DIAGRAMHEADERMODELITEM_H

#include <memory>
#include <ELFHeader.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ModelHelpers.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"

class ELFHeaderModelItem : public ELFModelItem {
    Q_OBJECT

    HEX_ELF_PROP_DECL(type, Type)
    HEX_ELF_PROP_DECL(machine, Machine)
    HEX_ELF_PROP_DECL(version, Version)
    HEX_ELF_PROP_DECL(entry, Entry)
    HEX_ELF_PROP_DECL(phoff, Phoff)
    HEX_ELF_PROP_DECL(shoff, Shoff)
    HEX_ELF_PROP_DECL(flags, Flags)
    HEX_ELF_PROP_DECL(ehsize, Ehsize)
    HEX_ELF_PROP_DECL(phentsize, Phentsize)
    HEX_ELF_PROP_DECL(phnum, Phnum)
    HEX_ELF_PROP_DECL(shentsize, Shentsize)
    HEX_ELF_PROP_DECL(shnum, Shnum)
    HEX_ELF_PROP_DECL(shstrndx, Shstrndx)

    Q_PROPERTY(ELFSectionHeaderTableModelItem *sectionHeaderTable READ getSectionHeaderTable NOTIFY sectionHeaderTableChanged)
    Q_PROPERTY(ELFProgramHeaderTableModelItem *programHeaderTable READ getProgramHeaderTable NOTIFY programHeaderTableChanged)
public:
    explicit ELFHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf);

    ~ELFHeaderModelItem() override;

    bool isValid() const override;

    ELFSectionHeaderTableModelItem *getSectionHeaderTable() const;
    ELFProgramHeaderTableModelItem *getProgramHeaderTable() const;

signals:
    void sectionHeaderTableChanged(ELFSectionHeaderTableModelItem *value);
    void programHeaderTableChanged(ELFProgramHeaderTableModelItem *value);

protected:
    void onStructureChanged() final;

private:
    void setSizeInFile();

    ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem;
    ELFProgramHeaderTableModelItem *programHeaderTableModelItem;
};


#endif //PROJECTELF_DIAGRAMHEADERMODELITEM_H
