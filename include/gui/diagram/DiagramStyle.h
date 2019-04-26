//
// Created by MOmac on 17.04.2019.
//

#ifndef PROJECTELF_DIAGRAMSTYLE_H
#define PROJECTELF_DIAGRAMSTYLE_H

#include <QPen>
#include <QBrush>
#include <QObject>

class DiagramStyle : public QObject {
    Q_OBJECT
public:
    const QPen &getDefaultPen() const {
        return defaultPen;
    }

    const QBrush &getBgr() const {
        return bgr;
    }

    const QBrush &getBgrPattern() const {
        return bgrPattern;
    }

    const QBrush &getHeaderNodeBgr() const {
        return headerNodeBgr;
    }

    const QBrush &getSectionTableNodeBgr() const {
        return sectionTableNodeBgr;
    }

    const QBrush &getProgramTableNodeBgr() const {
        return programTableNodeBgr;
    }

    const QBrush &getSectionNodeBgr() const {
        return sectionNodeBgr;
    }

    const QBrush &getSegmentNodeBgr() const {
        return segmentNodeBgr;
    }

protected:
    static constexpr int NODE_OPACITY = 200;

    QPen defaultPen{QColor(0, 0, 0)};

    QBrush bgr{QColor(95, 110, 120)};
    QBrush bgrPattern{QColor(), Qt::BDiagPattern};

    QBrush headerNodeBgr{QColor(152, 210, 235, NODE_OPACITY)};

    QBrush sectionTableNodeBgr{QColor(213, 185, 66, NODE_OPACITY)};

    QBrush programTableNodeBgr{QColor(234, 140, 85, NODE_OPACITY)};

    QBrush sectionNodeBgr{QColor(214, 178, 21, NODE_OPACITY)};

    QBrush segmentNodeBgr{QColor(234, 112, 42, NODE_OPACITY)};
};


#endif //PROJECTELF_DIAGRAMSTYLE_H
