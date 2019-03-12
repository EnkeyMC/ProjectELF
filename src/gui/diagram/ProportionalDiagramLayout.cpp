//
// Created by MOmac on 11.03.2019.
//

#include <include/gui/diagram/ProportionalDiagramLayout.h>

#include "gui/diagram/ProportionalDiagramLayout.h"

const int ProportionalDiagramLayout::ARROW_SPACE_WIDTH = 50;
const int ProportionalDiagramLayout::COLUMN_WIDTH = 200;
const int ProportionalDiagramLayout::MIN_HEIGHT = 500;
const int ProportionalDiagramLayout::MAX_HEIGHT = 4000;


ProportionalDiagramLayout::ProportionalDiagramLayout(DiagramScene *diagram) : DiagramLayout(diagram) {

}

void ProportionalDiagramLayout::layoutNodes() {
    this->forEachNode([this](DiagramNode &node) {
        this->layoutNodeInHeight(node, MIN_HEIGHT);
    });

    double maxStretchRatio = 0;

    for (auto &linkNode : m_linkColumnSortedNodes) {
        if (linkNode->getNodeRect().height() < linkNode->getMinHeight()
                && linkNode->getNodeRect().height() > 0)
        {
            if (linkNode->getMinHeight() / static_cast<double>(linkNode->getNodeRect().height()) > maxStretchRatio) {
                maxStretchRatio = static_cast<double>(linkNode->getMinHeight()) / linkNode->getNodeRect().height();
            }
        }
    }

    for (auto &execNode : m_execColumnSortedNodes) {
        if (execNode->getNodeRect().height() < execNode->getMinHeight()
             && execNode->getNodeRect().height() > 0)
        {
            if (execNode->getMinHeight() / static_cast<double>(execNode->getNodeRect().height()) > maxStretchRatio) {
                maxStretchRatio = static_cast<double>(execNode->getMinHeight()) / execNode->getNodeRect().height();
            }
        }
    }

    this->forEachNode([this, maxStretchRatio](DiagramNode &node) {
        this->layoutNodeInHeight(node, static_cast<int>(MIN_HEIGHT * maxStretchRatio));
    });
}

void ProportionalDiagramLayout::paint(QPainter *painter) const {
    painter->setPen(QColor(0, 0, 0));
    painter->drawText(QRect(QPoint(40, 0), QSize(200, 70)), Qt::AlignCenter, "Linking view");
    painter->drawText(QRect(QPoint(240, 0), QSize(200, 70)), Qt::AlignCenter, "Execution view");

    painter->setPen(QPen(QBrush(QColor(0, 0, 0)), 1, Qt::DashLine));
    painter->drawLine(240, 0, 240, 70);

    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(ARROW_SPACE_WIDTH, 71, 2 * COLUMN_WIDTH, this->contentsHeight);

    painter->translate(0, 70);
    for (const auto &linkNode : m_linkColumnSortedNodes)
        linkNode->paint(painter);

    for (const auto &execNode : m_execColumnSortedNodes)
        execNode->paint(painter);
    painter->translate(0, -70);
}

void ProportionalDiagramLayout::layoutNodeInHeight(DiagramNode &node, int height) {
    QRect rect{};
    rect.setTop(static_cast<int>(height * node.getProportionalPosition() + 0.5) + 1);
    const double proportionalBottomPosition = node.getProportionalPosition() + node.getProportionalSize();
    rect.setBottom(static_cast<int>(height * proportionalBottomPosition + 0.5));
    rect.setLeft(node.getColumn() * COLUMN_WIDTH + ARROW_SPACE_WIDTH);
    rect.setWidth(COLUMN_WIDTH * node.getColspan());

    node.setNodeRect(rect);

    if (rect.bottom() > this->contentsHeight)
        this->contentsHeight = rect.bottom();
}
