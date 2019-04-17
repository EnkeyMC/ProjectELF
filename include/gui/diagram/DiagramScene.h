//
// Created by MOmac on 07.03.2019.
//

#ifndef PROJECTELF_DIAGRAMSCENE_H
#define PROJECTELF_DIAGRAMSCENE_H

#include <QQuickPaintedItem>
#include <QPointer>
#include <set>

#include "core/models/ELFModel.h"
#include "core/VerticalBinaryTree.h"
#include "core/IMouseListener.h"
#include "gui/diagram/DiagramNode.h"
#include "gui/diagram/DiagramLayout.h"
#include "gui/diagram/DiagramStyle.h"

class DiagramScene : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(ELFModel * model READ getModel WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding NOTIFY paddingChanged)
    Q_PROPERTY(int minWidth READ getMinWidth NOTIFY minWidthChanged)
    Q_PROPERTY(DiagramStyle * style READ getStyle WRITE setStyle NOTIFY styleChanged)

public:
    explicit DiagramScene(QQuickItem *parent = nullptr);

    ~DiagramScene() override;

    void paint(QPainter *painter) override;

    void setModel(ELFModel * model);
    ELFModel* getModel() const;

    void setPadding(int padding);
    int getPadding() const;

    int getMinWidth() const;

    QPoint getLayoutOffset() const;

    DiagramStyle *getStyle() const;
    void setStyle(DiagramStyle *style);

signals:
    void modelChanged(ELFModel * model);
    void paddingChanged(int padding);
    void minWidthChanged(int minWidth);
    void styleChanged(DiagramStyle *style);

private slots:
    void onModelChanged();
    void onLayoutChanged();

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void hoverMoveEvent(QHoverEvent *event) override;

    void setMinWidth(int minWidth);

    QPoint translateMousePos(QPoint point) const;
    QPointF translateMousePos(QPointF point) const;

    VerticalBinaryTree<IDiagramMouseListener> nodeTree;

    QPointer<ELFModel> model;
    QPointer<DiagramLayout> layout;
    QPointer<DiagramStyle> style;

    int padding;
    int minWidth;
};


#endif //PROJECTELF_DIAGRAMSCENE_H
