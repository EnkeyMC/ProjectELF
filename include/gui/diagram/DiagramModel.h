//
// Created by MOmac on 07.03.2019.
//

#ifndef PROJECTELF_DIAGRAMMODEL_H
#define PROJECTELF_DIAGRAMMODEL_H

#include <QObject>
#include "gui/diagram/DiagramModelItem.h"

class DiagramModel : public QObject {
    Q_OBJECT
public:
    explicit DiagramModel(QObject *parent = nullptr);

    ~DiagramModel() override;

    void addItem(DiagramModelItem *item);

    const std::vector<DiagramModelItem *> &getItems() const;

protected:
    std::vector<DiagramModelItem *> items;
};


#endif //PROJECTELF_DIAGRAMMODEL_H
