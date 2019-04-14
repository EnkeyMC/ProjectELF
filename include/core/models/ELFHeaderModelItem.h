//
// Created by MOmac on 15.03.2019.
//

#ifndef PROJECTELF_DIAGRAMHEADERMODELITEM_H
#define PROJECTELF_DIAGRAMHEADERMODELITEM_H

#include <memory>
#include <ELFHeader.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"

class ELFHeaderModelItem : public ELFModelItem {
    Q_OBJECT

    Q_PROPERTY(QString type         READ getType        WRITE setType       NOTIFY typeChanged)
    Q_PROPERTY(QString machine      READ getMachine     WRITE setMachine    NOTIFY machineChanged)
    Q_PROPERTY(QString version      READ getVersion     WRITE setVersion    NOTIFY versionChanged)
    Q_PROPERTY(QString entry        READ getEntry       WRITE setEntry      NOTIFY entryChanged)
    Q_PROPERTY(QString phoff        READ getPhoff       WRITE setPhoff      NOTIFY phoffChanged)
    Q_PROPERTY(QString shoff        READ getShoff       WRITE setShoff      NOTIFY shoffChanged)
    Q_PROPERTY(QString flags        READ getFlags       WRITE setFlags      NOTIFY flagsChanged)
    Q_PROPERTY(QString ehsize       READ getEhsize      WRITE setEhsize     NOTIFY ehsizeChanged)
    Q_PROPERTY(QString phentsize    READ getPhentsize   WRITE setPhentsize  NOTIFY phentsizeChanged)
    Q_PROPERTY(QString phnum        READ getPhnum       WRITE setPhnum      NOTIFY phnumChanged)
    Q_PROPERTY(QString shentsize    READ getShentsize   WRITE setShentsize  NOTIFY shentsizeChanged)
    Q_PROPERTY(QString shnum        READ getShnum       WRITE setShnum      NOTIFY shnumChanged)
    Q_PROPERTY(QString shstrndx     READ getShstrndx    WRITE setShstrndx   NOTIFY shstrndxChanged)

    Q_PROPERTY(QString dispType         READ getDispType        NOTIFY typeChanged)
    Q_PROPERTY(QString dispMachine      READ getDispMachine     NOTIFY machineChanged)
    Q_PROPERTY(QString dispVersion      READ getDispVersion     NOTIFY versionChanged)
    Q_PROPERTY(QString dispEntry        READ getDispEntry       NOTIFY entryChanged)
    Q_PROPERTY(QString dispPhoff        READ getDispPhoff       NOTIFY phoffChanged)
    Q_PROPERTY(QString dispShoff        READ getDispShoff       NOTIFY shoffChanged)
    Q_PROPERTY(QString dispFlags        READ getDispFlags       NOTIFY flagsChanged)
    Q_PROPERTY(QString dispEhsize       READ getDispEhsize      NOTIFY ehsizeChanged)
    Q_PROPERTY(QString dispPhentsize    READ getDispPhentsize   NOTIFY phentsizeChanged)
    Q_PROPERTY(QString dispPhnum        READ getDispPhnum       NOTIFY phnumChanged)
    Q_PROPERTY(QString dispShentsize    READ getDispShentsize   NOTIFY shentsizeChanged)
    Q_PROPERTY(QString dispShnum        READ getDispShnum       NOTIFY shnumChanged)
    Q_PROPERTY(QString dispShstrndx     READ getDispShstrndx    NOTIFY shstrndxChanged)

    Q_PROPERTY(ELFSectionHeaderTableModelItem *sectionHeaderTable READ getSectionHeaderTable NOTIFY sectionHeaderTableChanged)
    Q_PROPERTY(ELFProgramHeaderTableModelItem *programHeaderTable READ getProgramHeaderTable NOTIFY programHeaderTableChanged)
public:
    explicit ELFHeaderModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf);

    ~ELFHeaderModelItem() override;

    QString getType() const;
    QString getMachine() const;
    QString getVersion() const;
    QString getEntry() const;
    QString getPhoff() const;
    QString getShoff() const;
    QString getFlags() const;
    QString getEhsize() const;
    QString getPhentsize() const;
    QString getPhnum() const;
    QString getShentsize() const;
    QString getShnum() const;
    QString getShstrndx() const;

    QString getDispType() const;
    QString getDispMachine() const;
    QString getDispVersion() const;
    QString getDispEntry() const;
    QString getDispPhoff() const;
    QString getDispShoff() const;
    QString getDispFlags() const;
    QString getDispEhsize() const;
    QString getDispPhentsize() const;
    QString getDispPhnum() const;
    QString getDispShentsize() const;
    QString getDispShnum() const;
    QString getDispShstrndx() const;

    void setType(QString hexValue);
    void setMachine(QString hexValue);
    void setVersion(QString hexValue);
    void setEntry(QString hexValue);
    void setPhoff(QString hexValue);
    void setShoff(QString hexValue);
    void setFlags(QString hexValue);
    void setEhsize(QString hexValue);
    void setPhentsize(QString hexValue);
    void setPhnum(QString hexValue);
    void setShentsize(QString hexValue);
    void setShnum(QString hexValue);
    void setShstrndx(QString hexValue);

    ELFSectionHeaderTableModelItem *getSectionHeaderTable() const;
    ELFProgramHeaderTableModelItem *getProgramHeaderTable() const;

signals:
    void typeChanged(QString hexValue);
    void machineChanged(QString hexValue);
    void versionChanged(QString hexValue);
    void entryChanged(QString hexValue);
    void phoffChanged(QString hexValue);
    void shoffChanged(QString hexValue);
    void flagsChanged(QString hexValue);
    void ehsizeChanged(QString hexvalue);
    void phentsizeChanged(QString hexValue);
    void phnumChanged(QString hexValue);
    void shentsizeChanged(QString hexValue);
    void shnumChanged(QString hexValue);
    void shstrndxChanged(QString hexValue);

    void sectionHeaderTableChanged(ELFSectionHeaderTableModelItem *value);
    void programHeaderTableChanged(ELFProgramHeaderTableModelItem *value);

private:
    ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem;
    ELFProgramHeaderTableModelItem *programHeaderTableModelItem;
};


#endif //PROJECTELF_DIAGRAMHEADERMODELITEM_H
