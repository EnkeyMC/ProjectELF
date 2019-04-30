#ifndef OPENFILESMODEL_H
#define OPENFILESMODEL_H

#include "core/models/ListModelBase.h"
#include "core/models/ELFModel.h"

typedef struct {
    QString filepath;
    bool changed;
    ELFModel *elfModel;
} OpenFile;

class OpenFilesModel : public ListModelBase
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

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QHash<int, QByteArray> roleNames() const override;

signals:
    void fileOpened(int index);
    void error(QString title, QString description);

protected:
    QVariant getData(int idx, int role) const override;

private:
    QString getFilenameFromPath(QString path) const;

    QString getDisplayName(int row) const;

    QVector<OpenFile> openFileList;
};

#endif // OPENFILESMODEL_H
