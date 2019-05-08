//
// Created by MOmac on 17.03.2019.
//

#include <ELF.h>

#include "core/models/ELFSectionHeaderTableModelItem.h"

ELFSectionHeaderTableModelItem::ELFSectionHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf)
    : ELFModelItem(parent, std::move(elf)), listModel(nullptr)
{
    listModel = new ELFSectionHeaderListModel(this);
    emit listModelChanged();
    onStructureChanged();
}

ELFSectionHeaderTableModelItem::~ELFSectionHeaderTableModelItem() {
    delete listModel;
}

const std::vector<ELFSectionHeaderModelItem *> &ELFSectionHeaderTableModelItem::getSectionHeaders() const
{
    return listModel->getSectionHeaderModelItems();
}

ELFSectionHeaderListModel *ELFSectionHeaderTableModelItem::getListModel() const {
    return listModel;
}

bool ELFSectionHeaderTableModelItem::isValid() const {
    return addressInFile + sizeInFile <= elf->get_file_size();
}

void ELFSectionHeaderTableModelItem::onStructureChanged() {
    auto header = this->elf->get_header();
    auto sectionCount = this->elf->get_section_headers().size();
    sizeInFile = sectionCount * header->get_e_shentsize();
    addressInFile = header->get_e_shoff();
    listModel->clear();

    for (unsigned int i = 0; i < sectionCount; i++) {
        auto sectionHeaderModel = new ELFSectionHeaderModelItem(this->getModel(), this->elf, i);
        listModel->add(sectionHeaderModel);
        connect(sectionHeaderModel, &ELFModelItem::dataChanged, this, &ELFModelItem::dataChanged);
    }
}
