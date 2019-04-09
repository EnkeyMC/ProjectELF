//
// Created by MOmac on 15.03.2019.
//

#include <QDebug>

#include "core/models/ELFHeaderModelItem.h"

#define DEFAULT(x) if (header == nullptr) return x

ELFHeaderModelItem::ELFHeaderModelItem(ELFModel *parent, elf::ELFHeader *header)
    : ELFModelItem(parent), header(header),
      sectionHeaderTableModelItem(nullptr),
      programHeaderTableModelItem(nullptr)
{
    if (header == nullptr)
        return;

    if (header->get_e_shoff() != 0)
        sectionHeaderTableModelItem = new ELFSectionHeaderTableModelItem(parent);
    if (header->get_e_phoff() != 0)
        programHeaderTableModelItem = new ELFProgramHeaderTableModelItem(parent);
}

ELFHeaderModelItem::~ELFHeaderModelItem() {
    delete sectionHeaderTableModelItem;
    delete programHeaderTableModelItem;
}

QString ELFHeaderModelItem::getType() const
{
    DEFAULT(QString());
    return QString::number(header->get_e_type(), HEX);
}

void ELFHeaderModelItem::setType(QString type)
{
    header->set_e_type(static_cast<elf::Elf_Half>(type.toUInt(nullptr, HEX)));
    emit typeChanged(type);
}
