//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderTableModelItem.h"

ELFProgramHeaderTableModelItem::ELFProgramHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf)
    : ELFModelItem(parent, std::move(elf))
{
    auto header = this->elf->get_header();
    auto segmentCount = header->get_e_phnum();
    sizeInFile = segmentCount * header->get_e_phoff();
    addressInFile = header->get_e_phoff();

    for (unsigned i = 0; i < segmentCount; i++) {
        programHeaderModelItems.push_back(new ELFProgramHeaderModelItem(parent, this->elf, i));
    }
}

ELFProgramHeaderTableModelItem::~ELFProgramHeaderTableModelItem() {
    for (auto programHeaderModelItem : this->programHeaderModelItems)
        delete programHeaderModelItem;
}

const std::vector<ELFProgramHeaderModelItem *> &ELFProgramHeaderTableModelItem::getProgramHeaders() const
{
    return programHeaderModelItems;
}
