//
// Created by MOmac on 11.03.2019.
//

#include "gui/diagram/ProportionalDiagramLayout.h"

const int ProportionalDiagramLayout::ARROW_SPACE_WIDTH = 50;
const int ProportionalDiagramLayout::COLUMN_WIDTH = 200;
const int ProportionalDiagramLayout::MIN_HEIGHT = 500;
const int ProportionalDiagramLayout::MAX_HEIGHT = 4000;


ProportionalDiagramLayout::ProportionalDiagramLayout(DiagramScene *diagram) : DiagramLayout(diagram) {

}

void ProportionalDiagramLayout::layoutNodes() {
    for (auto &linkNode : m_linkColumnSortedNodes) {
        linkNode->setNodeRect(
                QRect(
                        0 + ARROW_SPACE_WIDTH,
                        static_cast<int>(MIN_HEIGHT * linkNode->getProportionalPosition()),
                        COLUMN_WIDTH * linkNode->getColspan(),
                        static_cast<int>(MIN_HEIGHT * linkNode->getProportionalSize())
                )
        );
    }

    for (auto &execNode : m_execColumnSortedNodes) {
        execNode->setNodeRect(
                QRect(
                        COLUMN_WIDTH + ARROW_SPACE_WIDTH,
                        static_cast<int>(MIN_HEIGHT * execNode->getProportionalPosition()),
                        COLUMN_WIDTH * execNode->getColspan(),
                        static_cast<int>(MIN_HEIGHT * execNode->getProportionalSize())
                )
        );
    }

    double maxStrechRatio = 0;

    for (auto &linkNode : m_linkColumnSortedNodes) {
        if (linkNode->getNodeRect().height() < linkNode->getMinHeight()
                && linkNode->getNodeRect().height() > 0)
        {
            if (linkNode->getMinHeight() / static_cast<double>(linkNode->getNodeRect().height()) > maxStrechRatio) {
                maxStrechRatio = static_cast<double>(linkNode->getMinHeight()) / linkNode->getNodeRect().height();
            }
        }
    }

    for (auto &execNode : m_execColumnSortedNodes) {
        if (execNode->getNodeRect().height() < execNode->getMinHeight()
             && execNode->getNodeRect().height() > 0)
        {
            if (execNode->getMinHeight() / static_cast<double>(execNode->getNodeRect().height()) > maxStrechRatio) {
                maxStrechRatio = static_cast<double>(execNode->getMinHeight()) / execNode->getNodeRect().height();
            }
        }
    }

    for (auto &linkNode : m_linkColumnSortedNodes) {
        linkNode->strech(maxStrechRatio);
    }

    for (auto &execNode : m_execColumnSortedNodes) {
        execNode->strech(maxStrechRatio);
    }
}

void ProportionalDiagramLayout::paint(QPainter *painter) const {
    painter->setPen(QColor(0, 0, 0));
    painter->drawText(QRect(QPoint(40, 0), QSize(200, 70)), Qt::AlignCenter, "Linking view");
    painter->drawText(QRect(QPoint(240, 0), QSize(200, 70)), Qt::AlignCenter, "Execution view");

    painter->setPen(QPen(QBrush(QColor(0, 0, 0)), 1, Qt::DashLine));
    painter->drawLine(240, 0, 240, 70);

    painter->setPen(QColor(0, 0, 0));

    for (const auto &linkNode : m_linkColumnSortedNodes)
        linkNode->paint(painter);

    for (const auto &execNode : m_execColumnSortedNodes)
        execNode->paint(painter);
}
