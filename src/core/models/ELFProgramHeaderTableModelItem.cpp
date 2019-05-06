//
// Created by MOmac on 17.03.2019.
//

#include "core/models/ELFProgramHeaderTableModelItem.h"

ELFProgramHeaderTableModelItem::ELFProgramHeaderTableModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf)
    : ELFModelItem(parent, std::move(elf))
{
    auto header = this->elf->get_header();
    auto segmentCount = header->get_e_phnum();
    sizeInFile = segmentCount * header->get_e_phoff();
    addressInFile = header->get_e_phoff();
    listModel = new ELFProgramHeaderListModel(this);
    emit listModelChanged();

    for (unsigned i = 0; i < segmentCount; i++) {
        auto programHeaderModel = new ELFProgramHeaderModelItem(parent, this->elf, i);
        listModel->add(programHeaderModel);
        connect(programHeaderModel, &ELFProgramHeaderModelItem::dataChanged, this, &ELFProgramHeaderTableModelItem::dataChanged);
    }
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
