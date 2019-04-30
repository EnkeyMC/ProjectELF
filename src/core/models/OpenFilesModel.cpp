#include <fstream>
#include <QDebug>
#include <QFile>
#include <ELFReader.h>
#include <ELFIssueException.h>

#include "core/models/OpenFilesModel.h"
#include "core/ELFIssueConverter.h"

OpenFilesModel::OpenFilesModel(QObject *parent)
    : ListModelBase(parent)
{
}

void OpenFilesModel::closeFile(int row)
{
    emit beginRemoveRows(QModelIndex(), row, row);
    openFileList.removeAt(row);
    emit endRemoveRows();
}

void OpenFilesModel::openFile(QString filepath)
{
    if (!filepath.startsWith("file:///")) {
        emit error(tr("Unsupported protocol"), tr("Application only supports file protocol."));
        return;
    }

    filepath.remove(0, strlen("file:///"));

    std::ifstream file{filepath.toLocal8Bit(), std::ios_base::in | std::ios_base::binary};
    if (!file.is_open()) {
        emit error(tr("Error opening file"), tr("File %1 could not be opened").arg(filepath));
        return;
    }

    std::shared_ptr<elf::ELF> elf = std::make_shared<elf::ELF>();
    elf::ELFReader reader{file, *elf};

    try {
        reader.parse();
    } catch (const elf::ELFIssueException &exception) {
        emit error(tr("Parsing error"), ELFIssueConverter::toReadable(exception.getIssue()));
        return;
    }

    auto *model = new ELFModel(elf, this);

    int index = openFileList.size();
    emit beginInsertRows(QModelIndex(), index, index);
    openFileList.append({filepath, false, model});
    emit endInsertRows();
    emit fileOpened(index);
}

int OpenFilesModel::rowCount(const QModelIndex &parent) const
{
    return openFileList.size();
}

QHash<int, QByteArray> OpenFilesModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[FilenameRole] = "filename";
    names[FilepathRole] = "filepath";
    names[DisplayNameRole] = "displayName";
    names[ChangedRole] = "changed";
    names[ELFModelRole] = "elfModel";
    return names;
}

QString OpenFilesModel::getFilenameFromPath(QString path) const
{
    return path.section("/", -1, -1);
}

QString OpenFilesModel::getDisplayName(int row) const
{
    return this->getFilenameFromPath(this->openFileList.at(row).filepath);
}

QVariant OpenFilesModel::getData(int idx, int role) const {
    const OpenFile item = openFileList.at(idx);

    switch (role) {
        case FilenameRole:
            return QVariant(this->getFilenameFromPath(item.filepath));
        case ChangedRole:
            return QVariant(item.changed);
        case DisplayNameRole:
            return QVariant(this->getDisplayName(idx));
        case FilepathRole:
            return QVariant(item.filepath);
        case ELFModelRole:
        {
            QVariant var;
            var.setValue(item.elfModel);
            return var;
        }
        default:
            return QVariant();
    }
}
