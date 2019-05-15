//
// Created by MOmac on 07.03.2019.
//

#ifndef PROJECTELF_DIAGRAMMODEL_H
#define PROJECTELF_DIAGRAMMODEL_H

#include <memory>
#include <QObject>
#include <ELF.h>

#include "core/models/ELFHeaderModelItem.h"
#include "core/models/ELFIssueListModel.h"
#include "core/models/ModelHelpers.h"

class ELFModel : public QObject {
    Q_OBJECT

    HEX_ELF_PROP_DECL(mag0, Mag0)
    HEX_ELF_PROP_DECL(mag1, Mag1)
    HEX_ELF_PROP_DECL(mag2, Mag2)
    HEX_ELF_PROP_DECL(mag3, Mag3)
    HEX_ELF_PROP_DECL(fileClass, FileClass)
    HEX_ELF_PROP_DECL(dataEncoding, DataEncoding)
    HEX_ELF_PROP_DECL(version, Version)
    HEX_ELF_PROP_DECL(osabi, Osabi)
    HEX_ELF_PROP_DECL(abiversion, Abiversion)

    Q_PROPERTY(ELFHeaderModelItem* header READ getHeader NOTIFY headerChanged)
    Q_PROPERTY(ELFIssueListModel* issueListModel READ getIssues NOTIFY issuesChanged)
    Q_PROPERTY(bool modified READ isModified WRITE setModified NOTIFY modifiedChanged)
public:

    explicit ELFModel(QObject *parent = nullptr);

    explicit ELFModel(std::shared_ptr<elf::ELF> elf, QObject *parent = nullptr);

    ~ELFModel() override;

    uint64_t getFileSize() const;

    ELFHeaderModelItem *getHeader() const;

    Q_INVOKABLE void reloadIssues();
    ELFIssueListModel *getIssues();

    bool isModified() const;

    void setModified(bool modified);

    void reloadStructure();

    std::shared_ptr<elf::ELF> getElf() const;

signals:
    void headerChanged(ELFHeaderModelItem *);
    void issuesChanged(ELFIssueListModel *);
    void modifiedChanged(bool modified);
    void dataChanged();
    void structureChanged();

protected:
    void loadStructure();

    ELFHeaderModelItem *headerModelItem;

    std::shared_ptr<elf::ELF> elf;
    ELFIssueListModel issueListModel;
    bool modified;
};


#endif //PROJECTELF_DIAGRAMMODEL_H
