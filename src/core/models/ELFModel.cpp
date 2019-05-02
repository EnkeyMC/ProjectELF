//
// Created by MOmac on 07.03.2019.
//

#include "core/models/ELFModel.h"
#include "core/ELFValueConverter.h"

#define DEFAULT(x) if (elf == nullptr) return x

ELFModel::ELFModel(QObject *parent) : ModelBase(parent), headerModelItem(nullptr), issueListModel(), modified(false)
{

}

ELFModel::ELFModel(std::shared_ptr<elf::ELF> elf, QObject *parent) : ModelBase(parent), elf(std::move(elf)) {
    this->headerModelItem = new ELFHeaderModelItem(this, this->elf);
    this->reloadIssues();
    connect(this, &ELFModel::modifiedChanged, this, &ELFModel::reloadIssues);
    connect(this->headerModelItem, &ELFHeaderModelItem::dataChanged, [=]() {this->setModified(true);});
}

ELFModel::~ELFModel() {
    delete headerModelItem;
}

uint64_t ELFModel::getFileSize() const {
    DEFAULT(0);
    return elf->get_file_size();
}

QString ELFModel::getMag0() const {
    DEFAULT(QString());
    return QString::number(elf->get_ei_mag0(), HEX);
}

QString ELFModel::getMag1() const {
    DEFAULT(QString());
    return QString::number(elf->get_ei_mag1(), HEX);
}

QString ELFModel::getMag2() const {
    DEFAULT(QString());
    return QString::number(elf->get_ei_mag2(), HEX);
}

QString ELFModel::getMag3() const {
    DEFAULT(QString());
    return QString::number(elf->get_ei_mag3(), HEX);
}

QString ELFModel::getFileClass() const {
    DEFAULT(QString());
    return QString::number(elf->get_ei_class(), HEX);
}

QString ELFModel::getDataEncoding() const {
    DEFAULT(QString());
    return QString::number(elf->get_ei_data(), HEX);
}

QString ELFModel::getVersion() const
{
    DEFAULT(QString());
    return QString::number(elf->get_ei_version(), HEX);
}

QString ELFModel::getOsabi() const
{
    DEFAULT(QString());
    return QString::number(elf->get_ei_osabi(), HEX);
}

QString ELFModel::getAbiversion() const
{
    DEFAULT(QString());
    return QString::number(elf->get_ei_abiversion(), HEX);
}

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

QString ELFModel::getDispFileClass() const
{
    DEFAULT(QString());
    return ELFValueConverter::eiClassToDisp(elf->get_ei_class());
}

QString ELFModel::getDispDataEncoding() const
{
    DEFAULT(QString());
    return ELFValueConverter::eiDataToDisp(elf->get_ei_data());
}

QString ELFModel::getDispVersion() const
{
    return QString("0x") + this->getVersion();
}

QString ELFModel::getDispOsabi() const
{
    DEFAULT(QString());
    return ELFValueConverter::eiOsabiToDisp(elf->get_ei_osabi());
}

QString ELFModel::getDispAbiversion() const
{
    return QString("0x") + this->getAbiversion();
}

void ELFModel::setMag0(const QString &hexValue) {
    elf->set_ei_mag0(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit mag0Changed(hexValue);
}

void ELFModel::setMag1(const QString &hexValue) {
    elf->set_ei_mag1(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit mag1Changed(hexValue);
}

void ELFModel::setMag2(const QString &hexValue) {
    elf->set_ei_mag2(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit mag2Changed(hexValue);
}

void ELFModel::setMag3(const QString &hexValue) {
    elf->set_ei_mag3(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit mag3Changed(hexValue);
}

void ELFModel::setFileClass(const QString &hexValue) {
    elf->set_ei_class(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit fileClassChanged(hexValue);
}

void ELFModel::setDataEncoding(const QString &hexValue) {
    elf->set_ei_data(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit dataEncodingChanged(hexValue);
}

void ELFModel::setVersion(const QString &hexValue)
{
    elf->set_ei_version(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit versionChanged(hexValue);
}

void ELFModel::setOsabi(const QString &hexValue)
{
    elf->set_ei_osabi(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit osabiChanged(hexValue);
}

void ELFModel::setAbiversion(const QString &hexValue)
{
    elf->set_ei_abiversion(static_cast<unsigned char>(hexValue.toUInt(nullptr, HEX)));
    emit abiversionChanged(hexValue);
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
