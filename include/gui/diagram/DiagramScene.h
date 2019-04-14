//
// Created by MOmac on 07.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSCENE_H
#define PROJECTELF_DIAGRAMSCENE_H

#include <QQuickPaintedItem>
#include <QPointer>
#include <set>

#include "include/core/models/ELFModel.h"
#include "DiagramNode.h"
#include "DiagramLayout.h"

class DiagramScene : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(ELFModel * model READ getModel WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding NOTIFY paddingChanged)
    Q_PROPERTY(int minWidth READ getMinWidth NOTIFY minWidthChanged)

public:
    explicit DiagramScene(QQuickItem *parent = nullptr);

    ~DiagramScene() override;

    void paint(QPainter *painter) override;

    void setModel(ELFModel * model);
    ELFModel* getModel() const;

    void setPadding(int padding);
    int getPadding() const;

    int getMinWidth() const;

signals:
    void modelChanged(ELFModel * model);
    void paddingChanged(int padding);
    void minWidthChanged(int minWidth);

private slots:
    void onModelChanged();

protected:
    void setMinWidth(int minWidth);

    QPointer<ELFModel> model;
    QPointer<DiagramLayout> layout;

    int padding;
    int minWidth;
};


#endif //PROJECTELF_DIAGRAMSCENE_H
