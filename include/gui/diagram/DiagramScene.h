//
// Created by MOmac on 07.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSCENE_H
#define PROJECTELF_DIAGRAMSCENE_H

#include <QQuickPaintedItem>
#include "DiagramModel.h"

class DiagramScene : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(DiagramModel * model READ getModel WRITE setModel NOTIFY modelChanged)

public:
    explicit DiagramScene(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;

    void setModel(DiagramModel * model);

    DiagramModel* getModel() const;

signals:
    void modelChanged();

protected:
    DiagramModel *m_model;
};


#endif //PROJECTELF_DIAGRAMSCENE_H
