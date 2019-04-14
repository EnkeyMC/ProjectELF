//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSegmentModelItem.h"

ELFSegmentModelItem::ELFSegmentModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    auto segment = this->elf->get_program_headers()[index];
    sizeInFile = segment->get_p_filesz();
    addressInFile = segment->get_p_offset();
}
