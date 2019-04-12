//
// Created by MOmac on 17.03.2019.
//

#include <ELF.h>

#include "core/models/ELFSectionHeaderTableModelItem.h"

ELFSectionHeaderTableModelItem::ELFSectionHeaderTableModelItem(ELFModel *parent, elf::ELF *elf)
    : ELFModelItem(parent), elf(elf)
{
    auto sectionCount = elf->get_header()->get_e_shnum();
    sizeInFile = sectionCount * elf->get_header()->get_e_shentsize();
    addressInFile = elf->get_header()->get_e_shoff();

    for (unsigned int i = 0; i < sectionCount; i++) {
        sectionHeaderModelItems.push_back(new ELFSectionHeaderModelItem(parent, elf->get_section_headers()[i]));
    }
}

ELFSectionHeaderTableModelItem::~ELFSectionHeaderTableModelItem() {
    for (auto sectionHeaderModelItem : this->sectionHeaderModelItems)
        delete sectionHeaderModelItem;
}

const std::vector<ELFSectionHeaderModelItem *> &ELFSectionHeaderTableModelItem::getSectionHeaders() const
{
    return sectionHeaderModelItems;
}
