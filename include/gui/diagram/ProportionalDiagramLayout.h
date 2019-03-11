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

protected:
    static const int ARROW_SPACE_WIDTH;
    static const int COLUMN_WIDTH;
    static const int MIN_HEIGHT;
    static const int MAX_HEIGHT;
};


#endif //PROJECTELF_PROPORTIONALDIAGRAMLAYOUT_H
