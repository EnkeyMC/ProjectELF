//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderModelItem.h"

ELFProgramHeaderModelItem::ELFProgramHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index), segmentModelItem(nullptr)
{
    segmentModelItem = new ELFSegmentModelItem(parent, this->elf, this->index);
}

ELFProgramHeaderModelItem::~ELFProgramHeaderModelItem() {
    delete segmentModelItem;
}

ELFSegmentModelItem *ELFProgramHeaderModelItem::getSegmentModelItem() const
{
    return this->segmentModelItem;
}
