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
    padding(20), minWidth(0), nodeTree(), scroll(0, 0)
{
    connect(this, &DiagramScene::modelChanged, this, &DiagramScene::onModelChanged);
    connect(this, &DiagramScene::repaint, this, &DiagramScene::onRepaint);
    connect(this, &DiagramScene::widthChanged, this, &DiagramScene::onWidthChanged);
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptHoverEvents(true);

    this->setRenderTarget(QQuickPaintedItem::RenderTarget::Image);
    this->layout = new ProportionalDiagramLayout(this);
    connect(this->layout, &DiagramLayout::layoutChanged, this, &DiagramScene::onLayoutChanged);

    this->setMinWidth(this->layout->getMinWidth() + 2*this->padding);

    emit modelChanged(this->model);
}

DiagramScene::~DiagramScene() {
    for (auto connection : connections)
        delete connection;

    delete layout;
}

void DiagramScene::paint(QPainter *painter) {
    auto offset = this->getLayoutOffset();
    painter->translate(scroll);
    painter->translate(offset);
    layout->paint(painter);
    painter->translate(layout->getNodeOffset());
    for (auto conn : connections)
        conn->paint(painter);
    painter->translate(-layout->getNodeOffset());
    painter->translate(-offset);
    painter->translate(-scroll);
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
    emit contentsSizeChanged();
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

    auto headerNode = new DiagramHeaderNode(this, header);
    this->layout->addLinkNode(headerNode);


    auto sectionHeaderTable = header->getSectionHeaderTable();
    if (sectionHeaderTable != nullptr) {
        auto sectionHeaderTableNode = new DiagramSectionHeaderTableNode(this, sectionHeaderTable);
        this->layout->addLinkNode(sectionHeaderTableNode);

        createConnection(headerNode, "e_shoff", sectionHeaderTableNode, Connection::LEFT);

        for (auto sectionHeader : sectionHeaderTable->getSectionHeaders()) {
            auto sectionNode = new DiagramSectionNode(this, sectionHeader->getSectionModelItem());
            this->layout->addLinkNode(sectionNode);
        }
    }

    auto programHeaderTable = header->getProgramHeaderTable();
    if (programHeaderTable != nullptr) {
        auto programHeaderTableNode = new DiagramProgramHeaderTableNode(this, programHeaderTable);
        this->layout->addExecNode(programHeaderTableNode);

        createConnection(headerNode, "e_phoff", programHeaderTableNode, Connection::RIGHT);

        for (auto programHeader : programHeaderTable->getProgramHeaders()) {
            auto segmentNode = new DiagramSegmentNode(this, programHeader->getSegmentModelItem());
            this->layout->addExecNode(segmentNode);
        }
    }

    this->layout->layoutNodes();
    this->setImplicitHeight(this->layout->getSize().height() + 2*getPadding());
}

void DiagramScene::createConnection(DiagramNode *nodeFrom,
        const QString &connPoint,
        DiagramNode *nodeTo,
        Connection::Side side)
{
    auto shtConnection = new Connection(this, side);
    shtConnection->getStartBindable().bindTo(*nodeFrom->getConnectionPoints().at(connPoint));
    shtConnection->getEndBindable().bindTo(nodeTo->getNodeBindable());
    connect(nodeFrom, &DiagramNode::hoverEntered, shtConnection, &Connection::setVisible);
    connect(nodeFrom, &DiagramNode::hoverLeaved, shtConnection, &Connection::setInvisible);
    connect(nodeTo, &DiagramNode::hoverEntered, shtConnection, &Connection::setVisible);
    connect(nodeTo, &DiagramNode::hoverLeaved, shtConnection, &Connection::setInvisible);
    connections.push_back(shtConnection);
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

    layout->forEachNode([&translatedEvent](DiagramNode &node) {node.hoverMoveEvent(&translatedEvent);});

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

    this->update();
    emit contentSizeChanged(this->getContentSize());
}

QPoint DiagramScene::getLayoutOffset() const {
    QRect paddingRect{padding, padding,
                      static_cast<int>(width() - padding * 2),
                      static_cast<int>(height() - padding * 2)};
    int horizontalCenteringPadding = 0;
    if (width() > getContentWidth())
        horizontalCenteringPadding = (paddingRect.width() - this->layout->getSize().width()) / 2;
    return {padding + horizontalCenteringPadding, padding};
}

QPoint DiagramScene::translateMousePos(QPoint point) const {
    return point - getLayoutOffset() - layout->getNodeOffset() - scroll;
}

QPointF DiagramScene::translateMousePos(QPointF point) const {
    return point - getLayoutOffset() - layout->getNodeOffset() - scroll;
}

DiagramStyle *DiagramScene::getStyle() const {
    return style;
}

void DiagramScene::setStyle(DiagramStyle *style) {
    this->style = style;
    emit styleChanged(style);
}

void DiagramScene::wheelEvent(QWheelEvent *event) {
    if (event->pixelDelta().x() != 0 && event->pixelDelta().y() != 0) {
        scroll = scroll + event->pixelDelta();
    } else {
        scroll = scroll + event->angleDelta();
    }

    clampScroll();

    event->accept();

    emit scrollXPositionChanged(getScrollXPosition());
    emit scrollYPositionChanged(getScrollYPosition());
    emit repaint();
}

void DiagramScene::clampScroll() {
    if (getContentHeight() > height()) {
        if (scroll.y() > 0)
            scroll.setY(0);
        else if (-scroll.y() > getContentHeight() - height())
            scroll.setY(static_cast<int>(- (getContentHeight() - height())));
    } else {
        scroll.setY(0);
    }

    if (getContentWidth() > width()) {
        if (scroll.x() > 0)
            scroll.setX(0);
        else if (-scroll.x() > getContentWidth() - width())
            scroll.setX(static_cast<int>(- (getContentWidth() - width())));
    } else {
        scroll.setX(0);
    }
}

QSize DiagramScene::getContentSize() const {
    return layout->getSize() + QSize(2*padding, 2*padding);
}

int DiagramScene::getContentHeight() const {
    return getContentSize().height();
}

int DiagramScene::getContentWidth() const {
    return getContentSize().width();
}

qreal DiagramScene::getScrollYPosition() const {
    return (-scroll.y()) / (static_cast<qreal>(getContentHeight()));
}

qreal DiagramScene::getScrollXPosition() const {
    return (-scroll.x()) / (static_cast<qreal>(getContentWidth()));
}

void DiagramScene::setScrollYPosition(qreal pos) {
    auto scrollY = static_cast<int>(-(pos * getContentHeight()));
    scroll.setY(scrollY);
    emit repaint();
}

void DiagramScene::setScrollXPosition(qreal pos) {
    auto scrollX = static_cast<int>(-(pos * getContentWidth()));
    scroll.setX(scrollX);
    emit repaint();
}

void DiagramScene::onRepaint() {
    this->update();
}

void DiagramScene::onWidthChanged() {
    if (width() > getContentWidth()) {
        scroll.setX(0);
        emit scrollXPositionChanged(getScrollXPosition());
    }
}

DiagramLayout *DiagramScene::getLayout() const {
    return layout;
}

void DiagramScene::scrollToAddress(elf::Elf64_Addr address) {
    auto proportionalOffset = static_cast<double>(layout->getSize().height() * address) / model->getFileSize();
    scroll.setY(- static_cast<int>(proportionalOffset - this->height() / 6));
    clampScroll();
    emit scrollYPositionChanged(getScrollYPosition());
}
