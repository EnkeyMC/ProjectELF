//
// Created by MOmac on 15.03.2019.
//

#include <QDebug>

#include "core/models/ELFHeaderModelItem.h"
#include "core/ELFValueConverter.h"

#define DEFAULT(x) if (elf->get_header() == nullptr) return x

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

QString ELFHeaderModelItem::getType() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_type(), HEX);
}

QString ELFHeaderModelItem::getMachine() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_machine(), HEX);
}

QString ELFHeaderModelItem::getVersion() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_version(), HEX);
}

QString ELFHeaderModelItem::getEntry() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_entry(), HEX);
}

QString ELFHeaderModelItem::getPhoff() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_phoff(), HEX);
}

QString ELFHeaderModelItem::getShoff() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_shoff(), HEX);
}

QString ELFHeaderModelItem::getFlags() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_flags(), HEX);
}

QString ELFHeaderModelItem::getEhsize() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_ehsize(), HEX);
}

QString ELFHeaderModelItem::getPhentsize() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_phentsize(), HEX);
}

QString ELFHeaderModelItem::getPhnum() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_phnum(), HEX);
}

QString ELFHeaderModelItem::getShentsize() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_shentsize(), HEX);
}

QString ELFHeaderModelItem::getShnum() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_shnum(), HEX);
}

QString ELFHeaderModelItem::getShstrndx() const
{
    DEFAULT(QString());
    return QString::number(elf->get_header()->get_e_shstrndx(), HEX);
}

QString ELFHeaderModelItem::getDispType() const
{
    DEFAULT(QString());
    return ELFValueConverter::eTypeToDisp(elf->get_header()->get_e_type());
}

QString ELFHeaderModelItem::getDispMachine() const
{
    DEFAULT(QString());
    return ELFValueConverter::eMachineToDisp(elf->get_header()->get_e_machine());
}

QString ELFHeaderModelItem::getDispVersion() const
{
    DEFAULT(QString());
    return ELFValueConverter::eVersionToDisp(elf->get_header()->get_e_version());
}

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

void ELFHeaderModelItem::setType(QString hexValue)
{
    elf->get_header()->set_e_type(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit typeChanged(hexValue);
}

void ELFHeaderModelItem::setMachine(QString hexValue)
{
    elf->get_header()->set_e_machine(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit typeChanged(hexValue);
}

void ELFHeaderModelItem::setVersion(QString hexValue)
{
    elf->get_header()->set_e_version(static_cast<elf::Elf_Word>(hexValue.toUInt(nullptr, HEX)));
    emit versionChanged(hexValue);
}

void ELFHeaderModelItem::setEntry(QString hexValue)
{
    elf->get_header()->set_e_entry(static_cast<elf::Elf64_Addr>(hexValue.toUInt(nullptr, HEX)));
    emit entryChanged(hexValue);
}

void ELFHeaderModelItem::setPhoff(QString hexValue)
{
    elf->get_header()->set_e_phoff(static_cast<elf::Elf64_Off>(hexValue.toUInt(nullptr, HEX)));
    emit phoffChanged(hexValue);
}

void ELFHeaderModelItem::setShoff(QString hexValue)
{
    elf->get_header()->set_e_shoff(static_cast<elf::Elf64_Off>(hexValue.toUInt(nullptr, HEX)));
    emit shoffChanged(hexValue);
}

void ELFHeaderModelItem::setFlags(QString hexValue)
{
    elf->get_header()->set_e_flags(static_cast<elf::Elf_Word>(hexValue.toUInt(nullptr, HEX)));
    emit flagsChanged(hexValue);
}

void ELFHeaderModelItem::setEhsize(QString hexValue)
{
    elf->get_header()->set_e_ehsize(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit ehsizeChanged(hexValue);
}

void ELFHeaderModelItem::setPhentsize(QString hexValue)
{
    elf->get_header()->set_e_phentsize(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit phentsizeChanged(hexValue);
}

void ELFHeaderModelItem::setPhnum(QString hexValue)
{
    elf->get_header()->set_e_phnum(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit phnumChanged(hexValue);
}

void ELFHeaderModelItem::setShentsize(QString hexValue)
{
    elf->get_header()->set_e_shentsize(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit shentsizeChanged(hexValue);
}

void ELFHeaderModelItem::setShnum(QString hexValue)
{
    elf->get_header()->set_e_shnum(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit shnumChanged(hexValue);
}

void ELFHeaderModelItem::setShstrndx(QString hexValue)
{
    elf->get_header()->set_e_shstrndx(static_cast<elf::Elf_Half>(hexValue.toUInt(nullptr, HEX)));
    emit shstrndxChanged(hexValue);
}

ELFSectionHeaderTableModelItem *ELFHeaderModelItem::getSectionHeaderTable() const
{
    return this->sectionHeaderTableModelItem;
}

ELFProgramHeaderTableModelItem *ELFHeaderModelItem::getProgramHeaderTable() const
{
    return this->programHeaderTableModelItem;
}
