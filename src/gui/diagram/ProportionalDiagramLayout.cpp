//
// Created by MOmac on 11.03.2019.
//

#include "gui/diagram/ProportionalDiagramLayout.h"
#include "gui/diagram/DiagramScene.h"

const int ProportionalDiagramLayout::ARROW_SPACE_WIDTH = 50;
const int ProportionalDiagramLayout::COLUMN_WIDTH = 200;
const int ProportionalDiagramLayout::HEADER_HEIGHT = 100;
const int ProportionalDiagramLayout::MIN_HEIGHT = 500;
const int ProportionalDiagramLayout::MAX_HEIGHT = 4000;
const int ProportionalDiagramLayout::COLUMN_COUNT = 4;
const int ProportionalDiagramLayout::COLUMNS_PER_SIDE = COLUMN_COUNT / 2;


ProportionalDiagramLayout::ProportionalDiagramLayout(DiagramScene *diagram) : DiagramLayout(diagram) {
    this->size.setWidth(COLUMN_COUNT*COLUMN_WIDTH);
    this->minWidth = getSize().width();
}

void ProportionalDiagramLayout::layoutNodes() {
    this->forEachNode([this](DiagramNode &node) {
        this->layoutNodeInHeight(node, MIN_HEIGHT);
    });

    double maxStretchRatio = 1;

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

    DiagramLayout::layoutNodes();
}

void ProportionalDiagramLayout::layoutNodeInHeight(DiagramNode &node, int height) {
    QRect rect{};
    rect.setTop(static_cast<int>(height * node.getProportionalPosition() + 0.5) + 1);
    const double proportionalBottomPosition = node.getProportionalPosition() + node.getProportionalSize();
    rect.setBottom(static_cast<int>(height * proportionalBottomPosition + 0.5));
    rect.setLeft(COLUMN_WIDTH * node.getColumn());
    rect.setWidth(COLUMN_WIDTH * node.getColspan());

    node.setNodeRect(rect);

    if (rect.bottom() > this->size.height())
        this->size.setHeight(rect.bottom());
}

void ProportionalDiagramLayout::paint(QPainter *painter) const {
    this->paintHeader(painter);

    auto offset = getNodeOffset();
    painter->translate(offset);

    this->paintNodeBackground(painter);
    this->paintColumnBorders(painter);

    for (const auto &linkNode : linkColumnSortedNodes)
        linkNode->paint(painter);

    for (const auto &execNode : execColumnSortedNodes)
        execNode->paint(painter);

    painter->translate(-offset);
}

QSize ProportionalDiagramLayout::getSize() const {
    return this->size + QSize(2*ARROW_SPACE_WIDTH, HEADER_HEIGHT);
}

QPoint ProportionalDiagramLayout::getNodeOffset() const {
    return {ARROW_SPACE_WIDTH, HEADER_HEIGHT};
}

int ProportionalDiagramLayout::getContentWidth() const {
    return COLUMN_WIDTH*COLUMN_COUNT;
}

int ProportionalDiagramLayout::getArrowSpace() const {
    return ARROW_SPACE_WIDTH;
}

void ProportionalDiagramLayout::paintHeader(QPainter *painter) const {
    painter->translate(ARROW_SPACE_WIDTH, 0);

    painter->setPen(diagram->getStyle()->getDefaultPen());
    int center = COLUMN_WIDTH*COLUMNS_PER_SIDE;
    auto headerLabelRect = QRect(0, 0, COLUMN_WIDTH * COLUMNS_PER_SIDE, static_cast<int>(2 * (HEADER_HEIGHT / 3.0)));
    painter->drawText(headerLabelRect, Qt::AlignCenter, "Linking view");
    painter->drawText(headerLabelRect.translated(COLUMNS_PER_SIDE * COLUMN_WIDTH, 0), Qt::AlignCenter, "Execution view");

    painter->setPen(QPen(QBrush(QColor(0, 0, 0)), 1, Qt::DashLine));
    painter->drawLine(center, 0, center, HEADER_HEIGHT);

    auto subheaderLabelRect = QRect(headerLabelRect.bottomLeft(),
            QSize(headerLabelRect.width() / 2, HEADER_HEIGHT - headerLabelRect.height()));
    painter->drawText(subheaderLabelRect, Qt::AlignCenter, "Sections");
    subheaderLabelRect.translate(subheaderLabelRect.width(), 0);
    painter->drawText(subheaderLabelRect, Qt::AlignCenter, "Linking headers");
    painter->drawLine(subheaderLabelRect.topLeft(), subheaderLabelRect.bottomLeft());
    subheaderLabelRect.translate(subheaderLabelRect.width(), 0);
    painter->drawText(subheaderLabelRect, Qt::AlignCenter, "Execution headers");
    subheaderLabelRect.translate(subheaderLabelRect.width(), 0);
    painter->drawText(subheaderLabelRect, Qt::AlignCenter, "Segments");
    painter->drawLine(subheaderLabelRect.topLeft(), subheaderLabelRect.bottomLeft());

    painter->translate(-ARROW_SPACE_WIDTH, 0);
}

void ProportionalDiagramLayout::paintNodeBackground(QPainter *painter) const {
    painter->setPen(diagram->getStyle()->getDefaultPen());
    painter->setBrush(diagram->getStyle()->getBgr());
    QRect background{0, 1, COLUMN_COUNT * COLUMN_WIDTH, this->size.height()};
    painter->drawRect(background);
    painter->setBrush(diagram->getStyle()->getBgrPattern());
    painter->drawRect(background);
}

void ProportionalDiagramLayout::paintColumnBorders(QPainter *painter) const {
    painter->setPen(QColor(0, 0, 0, 50));

    for (int i = 0; i < COLUMN_COUNT; i++) {
        painter->drawLine(COLUMN_WIDTH * i, 1, COLUMN_WIDTH * i, this->size.height());
    }
}
