//
// Created by MOmac on 07.03.2019.
//

#include "core/models/ELFModel.h"
#include "core/ELFValueConvertor.h"

#define DEFAULT(x) if (elf == nullptr) return x

ELFModel::ELFModel(QObject *parent) : ModelBase(parent), headerModelItem(nullptr)
{

}

ELFModel::ELFModel(std::shared_ptr<elf::ELF> elf, QObject *parent) : ModelBase(parent), elf(std::move(elf)) {
    this->headerModelItem = new ELFHeaderModelItem(this, this->elf->get_header());
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
    return ELFValueConvertor::eiClassToDisp(elf->get_ei_class());
}

QString ELFModel::getDispDataEncoding() const
{
    DEFAULT(QString());
    return ELFValueConvertor::eiDataToDisp(elf->get_ei_data());
}

void ELFModel::setMag0(const QString &value) {
    elf->set_ei_mag0(static_cast<unsigned char>(value.toUInt(nullptr, HEX)));
    emit mag0Changed(value);
}

void ELFModel::setMag1(const QString &value) {
    elf->set_ei_mag1(static_cast<unsigned char>(value.toUInt(nullptr, HEX)));
    emit mag1Changed(value);
}

void ELFModel::setMag2(const QString &value) {
    elf->set_ei_mag2(static_cast<unsigned char>(value.toUInt(nullptr, HEX)));
    emit mag2Changed(value);
}

void ELFModel::setMag3(const QString &value) {
    elf->set_ei_mag3(static_cast<unsigned char>(value.toUInt(nullptr, HEX)));
    emit mag3Changed(value);
}

void ELFModel::setFileClass(const QString &value) {
    elf->set_ei_class(static_cast<unsigned char>(value.toUInt(nullptr, HEX)));
    emit fileClassChanged(value);
}

void ELFModel::setDataEncoding(const QString &value) {
    elf->set_ei_data(static_cast<unsigned char>(value.toUInt(nullptr, HEX)));
    emit dataEncodingChanged(value);
}
