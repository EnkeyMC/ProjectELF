//
// Created by MOmac on 11.03.2019.
//

#include <include/gui/diagram/ProportionalDiagramLayout.h>

#include "gui/diagram/ProportionalDiagramLayout.h"

const int ProportionalDiagramLayout::ARROW_SPACE_WIDTH = 50;
const int ProportionalDiagramLayout::COLUMN_WIDTH = 200;
const int ProportionalDiagramLayout::HEADER_HEIGHT = 70;
const int ProportionalDiagramLayout::MIN_HEIGHT = 500;
const int ProportionalDiagramLayout::MAX_HEIGHT = 4000;


ProportionalDiagramLayout::ProportionalDiagramLayout(DiagramScene *diagram) : DiagramLayout(diagram) {
    this->contentsSize.setWidth(2*COLUMN_WIDTH);
    this->minWidth = getSize().width();
}

void ProportionalDiagramLayout::layoutNodes() {
    this->forEachNode([this](DiagramNode &node) {
        this->layoutNodeInHeight(node, MIN_HEIGHT);
    });

    double maxStretchRatio = 0;

    this->forEachNode([&maxStretchRatio](DiagramNode &node) {
        if (node.getNodeRect().height() < node.getMinHeight()
                && node.getNodeRect().height() > 0)
        {
            if (node.getMinHeight() / static_cast<double>(node.getNodeRect().height()) > maxStretchRatio) {
                maxStretchRatio = static_cast<double>(node.getMinHeight()) / node.getNodeRect().height();
            }
        }
    });

    this->forEachNode([this, maxStretchRatio](DiagramNode &node) {
        this->layoutNodeInHeight(node, static_cast<int>(MIN_HEIGHT * maxStretchRatio));
    });
}

void ProportionalDiagramLayout::paint(QPainter *painter) const {
    painter->setPen(QColor(0, 0, 0));
    painter->drawText(QRect(QPoint(ARROW_SPACE_WIDTH, 0), QSize(COLUMN_WIDTH, HEADER_HEIGHT)), Qt::AlignCenter, "Linking view");
    painter->drawText(QRect(QPoint(COLUMN_WIDTH + ARROW_SPACE_WIDTH, 0), QSize(COLUMN_WIDTH, HEADER_HEIGHT)), Qt::AlignCenter, "Execution view");

    painter->setPen(QPen(QBrush(QColor(0, 0, 0)), 1, Qt::DashLine));
    painter->drawLine(COLUMN_WIDTH + ARROW_SPACE_WIDTH, 0, COLUMN_WIDTH + ARROW_SPACE_WIDTH, HEADER_HEIGHT);

    painter->setPen(QColor(0, 0, 0));
    painter->drawRect(ARROW_SPACE_WIDTH, HEADER_HEIGHT + 1, 2 * COLUMN_WIDTH, this->contentsSize.height());

    painter->translate(0, HEADER_HEIGHT);
    for (const auto &linkNode : linkColumnSortedNodes)
        linkNode->paint(painter);

    for (const auto &execNode : execColumnSortedNodes)
        execNode->paint(painter);
    painter->translate(0, -HEADER_HEIGHT);
}

void ProportionalDiagramLayout::layoutNodeInHeight(DiagramNode &node, int height) {
    QRect rect{};
    rect.setTop(static_cast<int>(height * node.getProportionalPosition() + 0.5) + 1);
    const double proportionalBottomPosition = node.getProportionalPosition() + node.getProportionalSize();
    rect.setBottom(static_cast<int>(height * proportionalBottomPosition + 0.5));
    rect.setLeft(node.getColumn() * COLUMN_WIDTH + ARROW_SPACE_WIDTH);
    rect.setWidth(COLUMN_WIDTH * node.getColspan());

    node.setNodeRect(rect);

    if (rect.bottom() > this->contentsSize.height())
        this->contentsSize.setHeight(rect.bottom());
}

QSize ProportionalDiagramLayout::getSize() const {
    return this->contentsSize + QSize(2*ARROW_SPACE_WIDTH, HEADER_HEIGHT);
}
