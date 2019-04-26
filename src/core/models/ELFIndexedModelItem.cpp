//
// Created by MOmac on 14.04.2019.
//

#include "core/models/ELFIndexedModelItem.h"

ELFIndexedModelItem::ELFIndexedModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFModelItem(parent, std::move(elf)), index(index)
{

}

unsigned int ELFIndexedModelItem::getIndex() const {
    return index;
}
