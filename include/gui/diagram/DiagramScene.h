//
// Created by MOmac on 07.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSCENE_H
#define PROJECTELF_DIAGRAMSCENE_H

#include <QQuickPaintedItem>
#include <QPointer>
#include <set>

#include "DiagramModel.h"
#include "DiagramNode.h"
#include "DiagramLayout.h"

class DiagramScene : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(DiagramModel * model READ getModel WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding NOTIFY paddingChanged);
    Q_PROPERTY(int minWidth READ getMinWidth NOTIFY minWidthChanged);

public:
    explicit DiagramScene(QQuickItem *parent = nullptr);

    ~DiagramScene() override;

    void paint(QPainter *painter) override;

    void setModel(DiagramModel * model);
    DiagramModel* getModel() const;

    void setPadding(int padding);
    int getPadding() const;

    int getMinWidth() const;

signals:
    void modelChanged(DiagramModel * model);
    void paddingChanged(int padding);
    void minWidthChanged(int minWidth);

protected:
    void setMinWidth(int minWidth);

    QPointer<DiagramModel> m_model;
    QPointer<DiagramLayout> m_layout;

    int m_padding;
    int m_minWidth;
};


#endif //PROJECTELF_DIAGRAMSCENE_H
