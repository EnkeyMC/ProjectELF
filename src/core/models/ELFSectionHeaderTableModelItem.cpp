//
// Created by MOmac on 17.03.2019.
//

#include <ELF.h>

#include "core/models/ELFSectionHeaderTableModelItem.h"

ELFSectionHeaderTableModelItem::ELFSectionHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf)
    : ELFModelItem(parent, std::move(elf))
{
    auto header = this->elf->get_header();
    auto sectionCount = header->get_e_shnum();
    sizeInFile = sectionCount * header->get_e_shentsize();
    addressInFile = header->get_e_shoff();

    for (unsigned int i = 0; i < sectionCount; i++) {
        auto sectionHeaderModel = new ELFSectionHeaderModelItem(parent, this->elf, i);
        sectionHeaderModelItems.push_back(sectionHeaderModel);
        connect(sectionHeaderModel, &ELFModelItem::dataChanged, this, &ELFModelItem::dataChanged);
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
