//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderTableModelItem.h"

ELFProgramHeaderTableModelItem::ELFProgramHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf)
    : ELFModelItem(parent, std::move(elf)), listModel(nullptr)
{
    listModel = new ELFProgramHeaderListModel(this);
    emit listModelChanged();
    onStructureChanged();
}

ELFProgramHeaderTableModelItem::~ELFProgramHeaderTableModelItem() {
    delete listModel;
}

const std::vector<ELFProgramHeaderModelItem *> &ELFProgramHeaderTableModelItem::getProgramHeaders() const
{
    return listModel->getProgramHeaderModelItems();
}

ELFProgramHeaderListModel *ELFProgramHeaderTableModelItem::getListModel() const {
    return listModel;
}

bool ELFProgramHeaderTableModelItem::isValid() const {
    return addressInFile + sizeInFile <= elf->get_file_size();
}

void ELFProgramHeaderTableModelItem::onStructureChanged() {
    auto header = this->elf->get_header();
    auto segmentCount = this->elf->get_program_headers().size();
    sizeInFile = segmentCount * header->get_e_phoff();
    addressInFile = header->get_e_phoff();
    listModel->clear();

    for (unsigned i = 0; i < segmentCount; i++) {
        auto programHeaderModel = new ELFProgramHeaderModelItem(this->getModel(), this->elf, i);
        listModel->add(programHeaderModel);
        connect(programHeaderModel, &ELFProgramHeaderModelItem::dataChanged, this, &ELFProgramHeaderTableModelItem::dataChanged);
    }

    emit validChanged();
}
