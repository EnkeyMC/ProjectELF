//
// Created by MOmac on 15.03.2019.
//

#include <QDebug>

#include "core/models/ELFHeaderModelItem.h"
#include "core/ELFValueConverter.h"

#define DEFAULT(x) if (elf->get_header() == nullptr) return x
#define ELF_STRUCT elf->get_header()

ELFHeaderModelItem::ELFHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf)
    : ELFModelItem(parent, std::move(elf)),
      sectionHeaderTableModelItem(nullptr),
      programHeaderTableModelItem(nullptr)
{
    addressInFile = 0;
    auto header = this->elf->get_header();
    if (header == nullptr) {
        sizeInFile = 0;
        return;
    }

    sizeInFile = header->get_size();

    if (header->get_e_shoff() != 0) {
        sectionHeaderTableModelItem = new ELFSectionHeaderTableModelItem(parent, this->elf);
        connect(sectionHeaderTableModelItem, &ELFModelItem::dataChanged, this, &ELFModelItem::dataChanged);
    }
    if (header->get_e_phoff() != 0) {
        programHeaderTableModelItem = new ELFProgramHeaderTableModelItem(parent, this->elf);
        connect(programHeaderTableModelItem, &ELFModelItem::dataChanged, this, &ELFModelItem::dataChanged);
    }
}

ELFHeaderModelItem::~ELFHeaderModelItem() {
    delete sectionHeaderTableModelItem;
    delete programHeaderTableModelItem;
}

HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, type, Type, ELF_STRUCT, e_type, elf::Elf_Half)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, machine, Machine, ELF_STRUCT, e_machine, elf::Elf_Half)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, version, Version, ELF_STRUCT, e_version, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, entry, Entry, ELF_STRUCT, e_entry, elf::Elf64_Addr)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, phoff, Phoff, ELF_STRUCT, e_phoff, elf::Elf64_Off)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, shoff, Shoff, ELF_STRUCT, e_shoff, elf::Elf64_Off)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, flags, Flags, ELF_STRUCT, e_flags, elf::Elf_Word)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, ehsize, Ehsize, ELF_STRUCT, e_ehsize, elf::Elf_Half)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, phentsize, Phentsize, ELF_STRUCT, e_phentsize, elf::Elf_Half)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, phnum, Phnum, ELF_STRUCT, e_phnum, elf::Elf_Half)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, shentsize, Shentsize, ELF_STRUCT, e_shentsize, elf::Elf_Half)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, shnum, Shnum, ELF_STRUCT, e_shnum, elf::Elf_Half)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFHeaderModelItem, shstrndx, Shstrndx, ELF_STRUCT, e_shstrndx, elf::Elf_Half)
HEX_ELF_PROP_GETDISP_W_CONVERTER(ELFHeaderModelItem, Type, ELF_STRUCT, e_type, eTypeToDisp)
HEX_ELF_PROP_GETDISP_W_CONVERTER(ELFHeaderModelItem, Machine, ELF_STRUCT, e_machine, eMachineToDisp)
HEX_ELF_PROP_GETDISP_W_CONVERTER(ELFHeaderModelItem, Version, ELF_STRUCT, e_version, eVersionToDisp)

HEX_ELF_PROP_GETDISP_DEFAULT(ELFHeaderModelItem, Entry)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFHeaderModelItem, Phoff)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFHeaderModelItem, Shoff)
HEX_ELF_PROP_GETDISP_DEFAULT(ELFHeaderModelItem, Flags)
HEX_ELF_PROP_GETDISP_BYTES(ELFHeaderModelItem, Ehsize, ELF_STRUCT, e_ehsize)
HEX_ELF_PROP_GETDISP_BYTES(ELFHeaderModelItem, Phentsize, ELF_STRUCT, e_phentsize)
HEX_ELF_PROP_GETDISP_DECIMAL(ELFHeaderModelItem, Phnum, ELF_STRUCT, e_phnum)
HEX_ELF_PROP_GETDISP_BYTES(ELFHeaderModelItem, Shentsize, ELF_STRUCT, e_shentsize)
HEX_ELF_PROP_GETDISP_DECIMAL(ELFHeaderModelItem, Shnum, ELF_STRUCT, e_shnum)
HEX_ELF_PROP_GETDISP_DECIMAL(ELFHeaderModelItem, Shstrndx, ELF_STRUCT, e_shstrndx)


ELFSectionHeaderTableModelItem *ELFHeaderModelItem::getSectionHeaderTable() const
{
    return this->sectionHeaderTableModelItem;
}

ELFProgramHeaderTableModelItem *ELFHeaderModelItem::getProgramHeaderTable() const
{
    return this->programHeaderTableModelItem;
}

bool ELFHeaderModelItem::isValid() const {
    return true;
}
