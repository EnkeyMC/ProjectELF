//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionModelItem.h"

ELFSectionModelItem::ELFSectionModelItem(ELFModel *parent, elf::ELFSectionHeader *sectionHeader)
    : ELFModelItem(parent), sectionHeader(sectionHeader)
{
    this->sizeInFile = sectionHeader->get_sh_size();
    this->addressInFile = sectionHeader->get_sh_offset();
}
