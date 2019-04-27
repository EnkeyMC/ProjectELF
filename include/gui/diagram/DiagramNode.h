//
// Created by MOmac on 09.03.2019.
//

#ifndef PROJECTELF_DIAGRAMNODE_H
#define PROJECTELF_DIAGRAMNODE_H

#include <QPainter>
#include <map>

#include "gui/diagram/IDiagramMouseListener.h"
#include "gui/diagram/ConnectionPoint.h"

class DiagramScene;

using std::map;

class DiagramNode : public QObject, virtual public IDiagramMouseListener {
    Q_OBJECT
public:
    typedef enum {
        LEFT,
        RIGHT,
        BOTH
    } ViewSide;

    explicit DiagramNode(DiagramScene *diagram);

    ~DiagramNode() override;

    virtual void paint(QPainter *painter) const;

    virtual double getProportionalPosition() const = 0;

    virtual double getProportionalSize() const = 0;

    virtual int getMinHeight() const = 0;

    int getColspan() const;

    void setColspan(int colspan);

    const QRect &getNodeRect() const;

    void setNodeRect(const QRect &nodeRect);

    void setColumn(int column);

    int getColumn() const;

    ViewSide getViewSide() const;

    void setViewSide(ViewSide viewSide);

    bool operator<(const DiagramNode &rhs) const;

    QRect getBounds() const override;

    bool contains(const QPoint &point) const override;

    const map<QString, ConnectionPoint*> &getConnectionPoints() const;
    map<QString, ConnectionPoint*> &getConnectionPoints();

    Bindable<QPoint> & getNodeBindable();

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void nodeRectChanged(const QRect &nodeRect);
    void hoverEntered();
    void hoverLeaved();

private slots:
    void onNodeRectChanged();

protected:
    static const int CONN_POINT_GAP = 20;

    void registerConnectionPoint(ConnectionPoint *connectionPoint);

    void paintConnectionPoints(QPainter *painter) const;

    void hoverEnteredEvent() override;

    void hoverLeavedEvent() override;

    map<QString, ConnectionPoint*> connectionPoints;

    DiagramScene *diagram;

    QRect nodeRect;

    ViewSide viewSide;

    int colspan;
    int column;

    Bindable<QPoint> nodeBindable;
};


#endif //PROJECTELF_DIAGRAMNODE_H
