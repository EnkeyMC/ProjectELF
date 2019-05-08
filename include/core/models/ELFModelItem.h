//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMMODELITEM_H
#define PROJECTELF_DIAGRAMMODELITEM_H

#include <QObject>
#include <ELF.h>
#include <memory>

class ELFModel;

class ELFModelItem : public QObject {
    Q_OBJECT

public:
    explicit ELFModelItem(ELFModel *parent, std::shared_ptr<elf::ELF> elf);

    virtual bool isValid() const = 0;

    uint64_t getAddressInFile() const;

    uint64_t getSizeInFile() const;

    ELFModel * getModel() const;

signals:
    void dataChanged();
    void structureChanged();

protected:
    std::shared_ptr<elf::ELF> elf;

    uint64_t addressInFile;
    uint64_t sizeInFile;

};


#endif //PROJECTELF_DIAGRAMMODELITEM_H
