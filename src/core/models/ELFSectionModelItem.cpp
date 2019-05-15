//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFSectionModelItem.h"

ELFSectionModelItem::ELFSectionModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf, unsigned index)
    : ELFIndexedModelItem(parent, std::move(elf), index)
{
    onStructureChanged();
}

bool ELFSectionModelItem::isValid() const {
    return this->elf->get_section_headers()[this->index]->is_section_valid();
}

void ELFSectionModelItem::onStructureChanged() {
    auto sectionHeader = this->elf->get_section_headers()[this->index];
    if (sectionHeader->is_section_valid()) {
        if (sectionHeader->get_sh_type() == SHT_NOBITS)
            sizeInFile = 0;
        else
            this->sizeInFile = sectionHeader->get_sh_size();
        this->addressInFile = sectionHeader->get_sh_offset();
    } else {
        sizeInFile = 0;
        addressInFile = 0;
    }

    emit validChanged();
}

QString ELFSectionModelItem::getName() const {
    if (isValid())
        return QString::fromStdString(elf->get_name(elf->get_section_headers()[this->index]->get_sh_name()));
    return "";
}
