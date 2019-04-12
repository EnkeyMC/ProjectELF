//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderTableModelItem.h"

ELFProgramHeaderTableModelItem::ELFProgramHeaderTableModelItem(ELFModel *parent, elf::ELFHeader *header)
    : ELFModelItem(parent), header(header)
{
    auto segmentCount = header->get_e_phnum();
    sizeInFile = segmentCount * header->get_e_phoff();
    addressInFile = header->get_e_phoff();

    for (int i = 0; i < segmentCount; i++) {
        programHeaderModelItems.push_back(new ELFProgramHeaderModelItem(parent));
    }
}

ELFProgramHeaderTableModelItem::~ELFProgramHeaderTableModelItem() {
    for (auto programHeaderModelItem : this->programHeaderModelItems)
        delete programHeaderModelItem;
}
