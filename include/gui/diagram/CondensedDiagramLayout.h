//
// Created by MOmac on 10.03.2019.
//

#ifndef PROJECTELF_ELFDIAGRAMLAYOUT_H
#define PROJECTELF_ELFDIAGRAMLAYOUT_H

#include "DiagramLayout.h"

class CondensedDiagramLayout : public DiagramLayout {
    Q_OBJECT

public:
    CondensedDiagramLayout(DiagramScene *diagram);

    void layoutNodes() override;

    void paint(QPainter *painter) const override;

};


#endif //PROJECTELF_ELFDIAGRAMLAYOUT_H
