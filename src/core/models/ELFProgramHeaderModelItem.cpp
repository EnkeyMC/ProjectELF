//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderModelItem.h"

ELFProgramHeaderModelItem::ELFProgramHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index), segmentModelItem(nullptr)
{
    auto header = this->elf->get_header();
    sizeInFile = header->get_e_phentsize();
    addressInFile = header->get_e_phoff() + index * header->get_e_phentsize();
    segmentModelItem = new ELFSegmentModelItem(parent, this->elf, this->index);
}

ELFProgramHeaderModelItem::~ELFProgramHeaderModelItem() {
    delete segmentModelItem;
}

ELFSegmentModelItem *ELFProgramHeaderModelItem::getSegmentModelItem() const
{
    return this->segmentModelItem;
}
