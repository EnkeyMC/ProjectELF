#include <fstream>
#include <QDebug>
#include <QFile>
#include <ELFReader.h>

#include "include/core/models/OpenFilesModel.h"

OpenFilesModel::OpenFilesModel(QObject *parent)
    : QAbstractItemModel(parent)
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
        qDebug() << "ERROR: Application only supports file protocol.";
        return;  // TODO handle error
    }

    filepath.remove(0, strlen("file:///"));

    std::ifstream file{filepath.toLocal8Bit(), std::ios_base::in | std::ios_base::binary};
    if (!file.is_open()) {
        qDebug() << "ERROR: File " << filepath << " could not be opened";
        return;  // TODO handle error
    }

    std::shared_ptr<elf::ELF> elf = std::make_shared<elf::ELF>();
    elf::ELFReader reader{file, *elf};

    reader.parse_header();
    reader.parse_section_headers();
    reader.parse_program_headers();
    reader.parse_sections();
    reader.parse_segments();

    auto *model = new ELFModel(elf, this);

    int index = openFileList.size();
    emit beginInsertRows(QModelIndex(), index, index);
    openFileList.append({filepath, false, model});
    emit endInsertRows();
    emit fileOpened(index);
}

QModelIndex OpenFilesModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column, nullptr);
}

QModelIndex OpenFilesModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int OpenFilesModel::rowCount(const QModelIndex &parent) const
{
    return openFileList.size();
}

int OpenFilesModel::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant OpenFilesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const OpenFile item = openFileList.at(index.row());

    switch (role) {
    case FilenameRole:
        return QVariant(this->getFilenameFromPath(item.filepath));
    case ChangedRole:
        return QVariant(item.changed);
    case DisplayNameRole:
        return QVariant(this->getDisplayName(index.row()));
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

bool OpenFilesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        switch (role) {
        case FilepathRole:
            openFileList[index.row()].filepath = value.toString();
            break;
        case ChangedRole:
            openFileList[index.row()].changed = value.toBool();
            break;
        case ELFModelRole:
            openFileList[index.row()].elfModel = value.value<ELFModel*>();
            break;
        default:  // Read only roles
            return false;
        }

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags OpenFilesModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
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
