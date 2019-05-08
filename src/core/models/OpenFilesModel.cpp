#include <fstream>
#include <QDebug>
#include <QFile>
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
    delete openFileList.at(row).elfModel;
    openFileList.removeAt(row);
    emit endRemoveRows();
}

void OpenFilesModel::openFile(QString filepath)
{
    if (!filepath.startsWith("file:///")) {
        emit error(tr("Unsupported protocol"), tr("Application only supports file protocol."));
        return;
    }

    removeProtocol(filepath);

    for (int i = 0; i < openFileList.size(); i++) {
        if (openFileList[i].filepath == filepath) {
            emit fileOpened(i);
            return;
        }
    }

    std::ifstream file{filepath.toLocal8Bit(), std::ios_base::in | std::ios_base::binary};
    if (!file.is_open()) {
        emit error(tr("Error opening file"), tr("File %1 could not be opened").arg(filepath));
        return;
    }

    std::shared_ptr<elf::ELF> elf = std::make_shared<elf::ELF>();

    try {
        elf->load(file);
    } catch (const elf::ELFIssueException &exception) {
        emit error(tr("Parsing error"), ELFIssueConverter::toReadable(exception.getIssue()));
        return;
    } catch (const std::bad_alloc &excepction) {
        emit error(tr("Allocation error"), tr("File is too large to load"));
        return;
    }

    auto *model = new ELFModel(elf, this);

    int index = openFileList.size();
    connect(model, &ELFModel::modifiedChanged, [=]() {
        emit dataChanged(
                this->index(0, 0, QModelIndex()),
                this->index(openFileList.size() - 1, 0, QModelIndex()),
                QVector<int>() << ModifiedRole
        );
    });
    emit beginInsertRows(QModelIndex(), index, index);
    openFileList.append({filepath, model});
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
    names[ModifiedRole] = "changed";
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
        case ModifiedRole:
            return QVariant(item.elfModel->isModified());
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

void OpenFilesModel::saveFile(int row) {
    this->saveFileAs(row, "file:///" + openFileList.at(row).filepath);
}

void OpenFilesModel::saveFileAs(int row, QString filepath) {
    if (row < 0 || row >= openFileList.size())
        return;
    auto &openFile = openFileList.at(row);

    if (!filepath.startsWith("file:///")) {
        emit error(tr("Unsupported protocol"), tr("Application only supports file protocol."));
        return;
    }

    removeProtocol(filepath);

    std::ofstream file{filepath.toLocal8Bit(), std::ios_base::out | std::ios_base::binary | std::ios_base::trunc};
    if (!file.is_open()) {
        emit error(tr("Error opening file for saving"), tr("File %1 could not be opened for saving.").arg(filepath));
        return;
    }

    if (!openFile.elfModel->getElf()->save(file)) {
        emit error(tr("Error saving to file"), tr("Could not save to file %1.").arg(filepath));
        return;
    }

    openFile.elfModel->setModified(false);
    openFileList[row].filepath = filepath;
    emit dataChanged(index(row, 0, QModelIndex()), index(row, 0, QModelIndex()),
                     QVector<int>() << FilepathRole << FilenameRole << DisplayNameRole << ModifiedRole);
}

bool OpenFilesModel::hasUnsavedChanges() const
{
    for (auto openFile : openFileList) {
        if (openFile.elfModel->isModified())
            return true;
    }
    return false;
}

void OpenFilesModel::reloadStructure(int row)
{
    if (row >= 0 & row < openFileList.size()) {
        auto openFile = openFileList.at(row);
        openFile.elfModel->reloadStructure();
        emit dataChanged(index(row, 0, QModelIndex()), index(row, 0, QModelIndex()),
                         QVector<int>() << ELFModelRole);
    }
}

void OpenFilesModel::removeProtocol(QString &path) {
    path.remove(0, strlen("file:///"));
}
