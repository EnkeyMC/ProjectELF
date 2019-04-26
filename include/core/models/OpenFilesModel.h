#ifndef OPENFILESMODEL_H
#define OPENFILESMODEL_H

#include <QAbstractItemModel>

#include "core/models/ELFModel.h"

typedef struct {
    QString filepath;
    bool changed;
    ELFModel *elfModel;
} OpenFile;

class OpenFilesModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    enum {
        FilenameRole = Qt::UserRole + 1,
        FilepathRole,
        DisplayNameRole,
        ChangedRole,
        ELFModelRole
    };

    explicit OpenFilesModel(QObject *parent = nullptr);

    Q_INVOKABLE void closeFile(int row);

    Q_INVOKABLE void openFile(QString filepath);

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QHash<int, QByteArray> roleNames() const override;

signals:
    void fileOpened(int index);

private:
    QString getFilenameFromPath(QString path) const;

    QString getDisplayName(int row) const;

    QVector<OpenFile> openFileList;
};

#endif // OPENFILESMODEL_H
