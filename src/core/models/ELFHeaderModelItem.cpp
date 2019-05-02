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

    if (header->get_e_shoff() != 0)
        sectionHeaderTableModelItem = new ELFSectionHeaderTableModelItem(parent, this->elf);
    if (header->get_e_phoff() != 0)
        programHeaderTableModelItem = new ELFProgramHeaderTableModelItem(parent, this->elf);
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

QString ELFHeaderModelItem::getDispEntry() const
{
    return QString("0x") + this->getEntry();
}

QString ELFHeaderModelItem::getDispPhoff() const
{
    return QString("0x") + this->getPhoff();
}

QString ELFHeaderModelItem::getDispShoff() const
{
    return QString("0x") + this->getShoff();
}

QString ELFHeaderModelItem::getDispFlags() const
{
    return QString("0x") + this->getFlags();
}

QString ELFHeaderModelItem::getDispEhsize() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_ehsize());
}

QString ELFHeaderModelItem::getDispPhentsize() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_phentsize());
}

QString ELFHeaderModelItem::getDispPhnum() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_phnum());
}

QString ELFHeaderModelItem::getDispShentsize() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_shentsize());
}

QString ELFHeaderModelItem::getDispShnum() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_shnum());
}

QString ELFHeaderModelItem::getDispShstrndx() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_shstrndx());
}

ELFSectionHeaderTableModelItem *ELFHeaderModelItem::getSectionHeaderTable() const
{
    return this->sectionHeaderTableModelItem;
}

ELFProgramHeaderTableModelItem *ELFHeaderModelItem::getProgramHeaderTable() const
{
    return this->programHeaderTableModelItem;
}
