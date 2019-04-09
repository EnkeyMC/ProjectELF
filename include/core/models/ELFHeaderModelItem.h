//
// Created by MOmac on 15.03.2019.
//

#ifndef PROJECTELF_DIAGRAMHEADERMODELITEM_H
#define PROJECTELF_DIAGRAMHEADERMODELITEM_H

#include <ELFHeader.h>

#include "core/models/ELFModelItem.h"
#include "core/models/ELFSectionHeaderTableModelItem.h"
#include "core/models/ELFProgramHeaderTableModelItem.h"

class ELFHeaderModelItem : public ELFModelItem {
    Q_OBJECT

    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
public:
    explicit ELFHeaderModelItem(ELFModel *parent, elf::ELFHeader *header = nullptr);

    ~ELFHeaderModelItem() override;

    QString getType() const;

    void setType(QString type);

signals:
    void typeChanged(QString value);

private:
    elf::ELFHeader *header;

    ELFSectionHeaderTableModelItem *sectionHeaderTableModelItem;
    ELFProgramHeaderTableModelItem *programHeaderTableModelItem;
};


#endif //PROJECTELF_DIAGRAMHEADERMODELITEM_H
