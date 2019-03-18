//
// Created by MOmac on 07.03.2019.
//

#include "core/models/ELFModel.h"

ELFModel::ELFModel(std::shared_ptr<elf::ELF> elf, QObject *parent) : ModelBase(parent), elf(std::move(elf)) {

}

ELFModel::~ELFModel() {
    delete headerModelItem;
}

uint64_t ELFModel::getFileSize() const {
    return fileSize;
}

void ELFModel::setFileSize(uint64_t fileSize) {
    ELFModel::fileSize = fileSize;
}
