//
// Created by MOmac on 07.03.2019.
//

#include <QPainter>

#include "gui/diagram/DiagramScene.h"
#include "gui/diagram/ProportionalDiagramLayout.h"
#include "gui/diagram/nodes/DiagramHeaderNode.h"
#include "gui/diagram/nodes/DiagramProgramHeaderTableNode.h"
#include "gui/diagram/nodes/DiagramSectionHeaderTableNode.h"
#include "gui/diagram/nodes/DiagramSectionNode.h"
#include "gui/diagram/nodes/DiagramSegmentNode.h"


DiagramScene::DiagramScene(QQuickItem *parent)
    : QQuickPaintedItem(parent), model(nullptr),
    padding(20), minWidth(0), nodeTree()
{
    connect(this, &DiagramScene::modelChanged, this, &DiagramScene::onModelChanged);
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptHoverEvents(true);

    this->setRenderTarget(QQuickPaintedItem::RenderTarget::Image);
    this->layout = new ProportionalDiagramLayout(this);
    connect(this->layout, &DiagramLayout::layoutChanged, this, &DiagramScene::onLayoutChanged);

    this->setMinWidth(this->layout->getMinWidth() + 2*this->padding);

    emit modelChanged(this->model);
}

DiagramScene::~DiagramScene() {
    delete layout;
}

void DiagramScene::paint(QPainter *painter) {
    auto offset = this->getLayoutOffset();
    painter->translate(offset.x(), offset.y());
    layout->paint(painter);
    painter->translate(-offset.x(), -offset.y());
}

void DiagramScene::setModel(ELFModel *model) {
    if (model != this->model) {
        this->model = model;
        emit modelChanged(this->model);
    }
}

ELFModel *DiagramScene::getModel() const {
    return this->model;
}

void DiagramScene::setPadding(int padding) {
    this->padding = padding;
    emit paddingChanged(this->padding);
}

int DiagramScene::getPadding() const {
    return this->padding;
}

int DiagramScene::getMinWidth() const {
    return this->minWidth;
}

void DiagramScene::setMinWidth(int minWidth) {
    if (this->minWidth != minWidth) {
        this->minWidth = minWidth;
        emit minWidthChanged(minWidth);
    }
}

void DiagramScene::onModelChanged() {
    this->layout->clearNodes();

    if (this->model == nullptr) {
        this->setImplicitHeight(2*getPadding());
        return;
    }

    auto header = this->model->getHeader();
    if (header == nullptr) {
        this->setImplicitHeight(2*getPadding());
        return;
    }

    this->layout->addLinkNode(new DiagramHeaderNode(this, header));

    auto sectionHeaderTable = header->getSectionHeaderTable();
    if (sectionHeaderTable != nullptr) {
        auto sectionHeaderTableNode = new DiagramSectionHeaderTableNode(this, sectionHeaderTable);
        this->layout->addLinkNode(sectionHeaderTableNode);

        for (auto sectionHeader : sectionHeaderTable->getSectionHeaders()) {
            auto sectionNode = new DiagramSectionNode(this, sectionHeader->getSectionModelItem());
            this->layout->addLinkNode(sectionNode);
        }
    }

    auto programHeaderTable = header->getProgramHeaderTable();
    if (programHeaderTable != nullptr) {
        auto programHeaderTableNode = new DiagramProgramHeaderTableNode(this, programHeaderTable);
        this->layout->addExecNode(programHeaderTableNode);

        for (auto programHeader : programHeaderTable->getProgramHeaders()) {
            auto segmentNode = new DiagramSegmentNode(this, programHeader->getSegmentModelItem());
            this->layout->addExecNode(segmentNode);
        }
    }

    this->layout->layoutNodes();
    this->setImplicitHeight(this->layout->getSize().height() + 2*getPadding());
}

void DiagramScene::mousePressEvent(QMouseEvent *event) {
    QMouseEvent translatedEvent {
            event->type(),
            translateMousePos(event->localPos()),
            event->windowPos(),
            event->screenPos(),
            event->button(),
            event->buttons(),
            event->modifiers(),
            event->source()
    };

    auto targets = nodeTree.getContaining(translatedEvent.pos());
    for (auto target : targets)
        target->mousePressEvent(&translatedEvent);

    QQuickItem::mousePressEvent(event);
}

void DiagramScene::mouseReleaseEvent(QMouseEvent *event) {
    QMouseEvent translatedEvent {
            event->type(),
            translateMousePos(event->localPos()),
            event->windowPos(),
            event->screenPos(),
            event->button(),
            event->buttons(),
            event->modifiers(),
            event->source()
    };

    auto targets = nodeTree.getContaining(translatedEvent.pos());
    for (auto target : targets)
        target->mouseReleaseEvent(&translatedEvent);

    QQuickItem::mouseReleaseEvent(event);
}

void DiagramScene::hoverMoveEvent(QHoverEvent *event) {
    QHoverEvent translatedEvent{
            event->type(),
            translateMousePos(event->pos()),
            translateMousePos(event->oldPos()),
            event->modifiers()
    };
    auto targets = nodeTree.getContaining(translatedEvent.pos());
    for (auto target : targets)
        target->hoverMoveEvent(&translatedEvent);

    QQuickItem::hoverMoveEvent(event);
}

void DiagramScene::onLayoutChanged() {
    nodeTree.setBounds(QLine(0, 0, 0, static_cast<int>(this->height())));

    auto linkNodes = this->layout->getLinkColumnSortedNodes();
    for (auto node : linkNodes)
        nodeTree.insert(node);

    auto execNodes = this->layout->getExecColumnSortedNodes();
    for (auto node : execNodes)
        nodeTree.insert(node);
}

QPoint DiagramScene::getLayoutOffset() const {
    QRect paddingRect{padding, padding,
                      static_cast<int>(width() - padding * 2),
                      static_cast<int>(height() - padding * 2)};
    int horizontalCenteringPadding = (paddingRect.width() - this->layout->getSize().width()) / 2;
    return {padding + horizontalCenteringPadding, padding};
}

QPoint DiagramScene::translateMousePos(QPoint point) const {
    return point - getLayoutOffset() - layout->getNodeOffset();
}

QPointF DiagramScene::translateMousePos(QPointF point) const {
    return point - getLayoutOffset() - layout->getNodeOffset();
}

DiagramStyle *DiagramScene::getStyle() const {
    return style;
}

void DiagramScene::setStyle(DiagramStyle *style) {
    this->style = style;
    emit styleChanged(style);
}
