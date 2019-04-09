//
// Created by MOmac on 07.03.2019.
//

#ifndef PROJECTELF_DIAGRAMMODEL_H
#define PROJECTELF_DIAGRAMMODEL_H

#include <QObject>
#include <ELF.h>
#include <memory>

#include "core/ModelBase.h"
#include "core/models/ELFHeaderModelItem.h"

class ELFModel : public ModelBase {
    Q_OBJECT
    Q_PROPERTY(QString mag0 READ getMag0 WRITE setMag0 NOTIFY mag0Changed)
    Q_PROPERTY(QString mag1 READ getMag1 WRITE setMag1 NOTIFY mag1Changed)
    Q_PROPERTY(QString mag2 READ getMag2 WRITE setMag2 NOTIFY mag2Changed)
    Q_PROPERTY(QString mag3 READ getMag3 WRITE setMag3 NOTIFY mag3Changed)
    Q_PROPERTY(QString fileClass READ getFileClass WRITE setFileClass NOTIFY fileClassChanged)
    Q_PROPERTY(QString dataEncoding READ getDataEncoding WRITE setDataEncoding NOTIFY dataEncodingChanged)
    Q_PROPERTY(ELFHeaderModelItem* header READ getHeader NOTIFY headerChanged)

    Q_PROPERTY(QString dispMag0 READ getDispMag0 NOTIFY mag0Changed)
    Q_PROPERTY(QString dispMag1 READ getDispMag1 NOTIFY mag1Changed)
    Q_PROPERTY(QString dispMag2 READ getDispMag2 NOTIFY mag2Changed)
    Q_PROPERTY(QString dispMag3 READ getDispMag3 NOTIFY mag3Changed)
    Q_PROPERTY(QString dispFileClass READ getDispFileClass NOTIFY fileClassChanged)
    Q_PROPERTY(QString dispDataEncoding READ getDispDataEncoding NOTIFY dataEncodingChanged)
public:

    ELFModel(QObject *parent = nullptr);

    explicit ELFModel(std::shared_ptr<elf::ELF> elf, QObject *parent = nullptr);

    ~ELFModel() override;

    uint64_t getFileSize() const;

    QString getMag0() const;
    QString getMag1() const;
    QString getMag2() const;
    QString getMag3() const;
    QString getFileClass() const;
    QString getDataEncoding() const;
    ELFHeaderModelItem *getHeader() const;

    QString getDispMag0() const;
    QString getDispMag1() const;
    QString getDispMag2() const;
    QString getDispMag3() const;
    QString getDispFileClass() const;
    QString getDispDataEncoding() const;

    void setMag0(const QString &value);
    void setMag1(const QString &value);
    void setMag2(const QString &value);
    void setMag3(const QString &value);
    void setFileClass(const QString &value);
    void setDataEncoding(const QString &value);

signals:
    void mag0Changed(QString);
    void mag1Changed(QString);
    void mag2Changed(QString);
    void mag3Changed(QString);
    void fileClassChanged(QString);
    void dataEncodingChanged(QString);
    void headerChanged(ELFHeaderModelItem *);

protected:
    ELFHeaderModelItem *headerModelItem;

    std::shared_ptr<elf::ELF> elf;
};


#endif //PROJECTELF_DIAGRAMMODEL_H
