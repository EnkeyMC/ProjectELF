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
#include "gui/diagram/Connection.h"

class DiagramScene : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(ELFModel * model READ getModel WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(int padding READ getPadding WRITE setPadding NOTIFY paddingChanged)
    Q_PROPERTY(int minWidth READ getMinWidth NOTIFY minWidthChanged)
    Q_PROPERTY(DiagramStyle * style READ getStyle WRITE setStyle NOTIFY styleChanged)
    Q_PROPERTY(int contentHeight READ getContentHeight NOTIFY contentSizeChanged)
    Q_PROPERTY(int contentWidth READ getContentWidth NOTIFY contentSizeChanged)
    Q_PROPERTY(qreal scrollYPosition READ getScrollYPosition WRITE setScrollYPosition NOTIFY scrollYPositionChanged)
    Q_PROPERTY(qreal scrollXPosition READ getScrollXPosition WRITE setScrollXPosition NOTIFY scrollXPositionChanged)

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

    QSize getContentSize() const;

    int getContentHeight() const;
    int getContentWidth() const;

    DiagramLayout *getLayout() const;

    qreal getScrollYPosition() const;
    void setScrollYPosition(qreal pos);
    qreal getScrollXPosition() const;
    void setScrollXPosition(qreal pos);

signals:
    void modelChanged(ELFModel * model);
    void paddingChanged(int padding);
    void minWidthChanged(int minWidth);
    void styleChanged(DiagramStyle *style);
    void contentSizeChanged(QSize size);
    void scrollYPositionChanged(qreal pos);
    void scrollXPositionChanged(qreal pos);
    void repaint();
    void pushNodeToFront(DiagramNode *node);

public slots:
    void scrollTo(int y);

private slots:
    void onModelChanged();
    void onLayoutChanged();
    void onRepaint();
    void onWidthChanged();

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void hoverMoveEvent(QHoverEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void setMinWidth(int minWidth);

    void clampScroll();

    void createConnection(DiagramNode *nodeFrom, const QString &connPoint,
            DiagramNode *nodeTo, Side side, int level);

    void clearConnections();

    QPoint translateMousePos(QPoint point) const;
    QPointF translateMousePos(QPointF point) const;

    VerticalBinaryTree<IDiagramMouseListener> nodeTree;
    vector<Connection *> connections;

    QPointer<ELFModel> model;
    QPointer<DiagramLayout> layout;
    QPointer<DiagramStyle> style;

    int padding;
    int minWidth;

    QPoint scroll;
};


#endif //PROJECTELF_DIAGRAMSCENE_H
