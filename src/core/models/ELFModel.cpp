//
// Created by MOmac on 07.03.2019.
//

#include "core/models/ELFModel.h"
#include "core/ELFValueConverter.h"

#define DEFAULT(x) if (elf == nullptr) return x
#define ELF_STRUCT elf

ELFModel::ELFModel(QObject *parent) : ModelBase(parent), headerModelItem(nullptr), issueListModel(), modified(false)
{

}

ELFModel::ELFModel(std::shared_ptr<elf::ELF> elf, QObject *parent)
        : ModelBase(parent), elf(std::move(elf)), modified(false)
{
    this->headerModelItem = new ELFHeaderModelItem(this, this->elf);
    this->reloadIssues();
    connect(this, &ELFModel::modifiedChanged, this, &ELFModel::reloadIssues);
    connect(this, &ELFModel::dataChanged, [=]() {this->setModified(true);});
    connect(this->headerModelItem, &ELFModelItem::dataChanged, [=]() {this->setModified(true);});
}

ELFModel::~ELFModel() {
    delete headerModelItem;
}

uint64_t ELFModel::getFileSize() const {
    DEFAULT(0);
    return elf->get_file_size();
}

HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, mag0, Mag0, ELF_STRUCT, ei_mag0, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, mag1, Mag1, ELF_STRUCT, ei_mag1, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, mag2, Mag2, ELF_STRUCT, ei_mag2, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, mag3, Mag3, ELF_STRUCT, ei_mag3, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, fileClass, FileClass, ELF_STRUCT, ei_class, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, dataEncoding, DataEncoding, ELF_STRUCT, ei_data, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, version, Version, ELF_STRUCT, ei_version, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, osabi, Osabi, ELF_STRUCT, ei_osabi, unsigned char)
HEX_ELF_PROP_GET_GETBYTES_SET(ELFModel, abiversion, Abiversion, ELF_STRUCT, ei_abiversion, unsigned char)

HEX_ELF_PROP_GETDISP_W_CONVERTER(ELFModel, FileClass, ELF_STRUCT, ei_class, eiClassToDisp)
HEX_ELF_PROP_GETDISP_W_CONVERTER(ELFModel, DataEncoding, ELF_STRUCT, ei_data, eiDataToDisp)
HEX_ELF_PROP_GETDISP_W_CONVERTER(ELFModel, Osabi, ELF_STRUCT, ei_osabi, eiOsabiToDisp)

ELFHeaderModelItem *ELFModel::getHeader() const
{
    return this->headerModelItem;
}

QString ELFModel::getDispMag0() const
{
    DEFAULT(QString());
    if (std::isgraph(elf->get_ei_mag0()))
        return QString(elf->get_ei_mag0());
    else
        return QString();
}

QString ELFModel::getDispMag1() const
{
    DEFAULT(QString());
    if (std::isgraph(elf->get_ei_mag1()))
        return QString(elf->get_ei_mag1());
    else
        return QString();
}

QString ELFModel::getDispMag2() const
{
    DEFAULT(QString());
    if (std::isgraph(elf->get_ei_mag2()))
        return QString(elf->get_ei_mag2());
    else
        return QString();
}

QString ELFModel::getDispMag3() const
{
    DEFAULT(QString());
    if (std::isgraph(elf->get_ei_mag3()))
        return QString(elf->get_ei_mag3());
    else
        return QString();
}

QString ELFModel::getDispVersion() const
{
    return QString("0x") + this->getVersion();
}

QString ELFModel::getDispAbiversion() const
{
    return QString("0x") + this->getAbiversion();
}

void ELFModel::reloadIssues()
{
    this->issueListModel = elf->find_issues();
    emit issuesChanged(&this->issueListModel);
}

ELFIssueListModel *ELFModel::getIssues() {
    return &issueListModel;
}

bool ELFModel::isModified() const {
    return modified;
}

void ELFModel::setModified(bool modified) {
    this->modified = modified;
    emit modifiedChanged(modified);
}
