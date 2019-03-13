//
// Created by MOmac on 13.03.2019.
//

#ifndef PROJECTELF_DIAGRAMMODELITEM_H
#define PROJECTELF_DIAGRAMMODELITEM_H

#include <QObject>

class DiagramModel;

class DiagramModelItem : public QObject {
    Q_OBJECT

public:
    explicit DiagramModelItem(DiagramModel *parent);

    uint64_t getAddressInFile() const;

    uint64_t getSizeInFile() const;

protected:
    uint64_t addressInFile;
    uint64_t sizeInFile;

};


#endif //PROJECTELF_DIAGRAMMODELITEM_H
