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
public:
    explicit ELFModel(std::shared_ptr<elf::ELF> elf, QObject *parent = nullptr);

    ~ELFModel() override;

    uint64_t getFileSize() const;

    void setFileSize(uint64_t fileSize);

protected:
    ELFHeaderModelItem *headerModelItem;

    uint64_t fileSize;

    std::shared_ptr<elf::ELF> elf;
};


#endif //PROJECTELF_DIAGRAMMODEL_H
