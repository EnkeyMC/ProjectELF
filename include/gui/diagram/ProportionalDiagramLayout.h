//
// Created by MOmac on 11.03.2019.
//

#ifndef PROJECTELF_PROPORTIONALDIAGRAMLAYOUT_H
#define PROJECTELF_PROPORTIONALDIAGRAMLAYOUT_H

#include "gui/diagram/DiagramLayout.h"

class ProportionalDiagramLayout : public DiagramLayout {
    Q_OBJECT
public:
    explicit ProportionalDiagramLayout(DiagramScene *diagram);

    void layoutNodes() override;

    void paint(QPainter *painter) const override;

    QSize getSize() const override;

    QPoint getNodeOffset() const override;

    int getContentWidth() const override;

    int getArrowSpace() const override;

protected:
    void layoutNodeInHeight(DiagramNode &node, int height);

    void paintHeader(QPainter *painter) const;

    void paintNodeBackground(QPainter *painter) const;

    void paintColumnBorders(QPainter *painter) const;

    static const int ARROW_SPACE_WIDTH;
    static const int COLUMN_WIDTH;
    static const int COLUMN_COUNT;
    static const int COLUMNS_PER_SIDE;
    static const int HEADER_HEIGHT;
    static const int MIN_HEIGHT;
//    static const int MAX_HEIGHT;
};


#endif //PROJECTELF_PROPORTIONALDIAGRAMLAYOUT_H
