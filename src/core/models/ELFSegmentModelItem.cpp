//
// Created by MOmac on 17.03.2019.
//

#include "core/ELFValueConverter.h"
#include "core/models/ELFSegmentModelItem.h"

ELFSegmentModelItem::ELFSegmentModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    onStructureChanged();
}

bool ELFSegmentModelItem::isValid() const {
    return this->elf->get_program_headers()[index]->is_segment_valid();
}

void ELFSegmentModelItem::onStructureChanged() {
    auto segment = this->elf->get_program_headers()[index];
    if (segment->is_segment_valid()) {
        sizeInFile = segment->get_p_filesz();
        addressInFile = segment->get_p_offset();
    } else {
        sizeInFile = 0;
        addressInFile = 0;
    }

    emit validChanged();
}

QString ELFSegmentModelItem::getType() const {
    if (isValid())
        return ELFValueConverter::pTypeToDisp(elf->get_program_headers()[index]->get_p_type());
    return "";
}
