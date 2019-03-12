//
// Created by MOmac on 09.03.2019.
//

#ifndef PROJECTELF_DIAGRAMNODE_H
#define PROJECTELF_DIAGRAMNODE_H

#include <QPainter>

class DiagramScene;

class DiagramNode {
public:
    explicit DiagramNode(DiagramScene *diagram);

    virtual ~DiagramNode();

    virtual void paint(QPainter *painter) const = 0;

    virtual double getProportionalPosition() const = 0;

    virtual double getProportionalSize() const = 0;

    virtual int getMinHeight() const = 0;

    int getColspan() const;

    const QRect &getNodeRect() const;

    void setNodeRect(const QRect &nodeRect);

    void setHeight(int height);

    void setColumn(int column);

    int getColumn() const;

    void moveTop(int y);

    void setBottom(int y);

    void stretch(double factor);

    bool operator<(const DiagramNode &rhs) const;
protected:
    DiagramScene *diagram;

    QRect nodeRect;

    int colspan;
    int column;
};


#endif //PROJECTELF_DIAGRAMNODE_H
