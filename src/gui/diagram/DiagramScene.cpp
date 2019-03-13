//
// Created by MOmac on 07.03.2019.
//

#include <QPainter>

#include "gui/diagram/DiagramScene.h"
#include "gui/diagram/ProportionalDiagramLayout.h"
#include "gui/diagram/DiagramHeaderNode.h"
#include "gui/diagram/DiagramSectionHeadersNode.h"

DiagramScene::DiagramScene(QQuickItem *parent) : QQuickPaintedItem(parent) {
    this->setRenderTarget(QQuickPaintedItem::RenderTarget::Image);
    this->m_model = nullptr;
    this->m_layout = new ProportionalDiagramLayout(this);
    this->setPadding(20);

    // Test nodes
    this->m_layout->addLinkNode(new DiagramHeaderNode(this));
    this->m_layout->addLinkNode(new DiagramSectionHeadersNode(this, 0.2, 0.1));
    this->m_layout->addLinkNode(new DiagramSectionHeadersNode(this, 0.3, 0.3));
    this->m_layout->addLinkNode(new DiagramSectionHeadersNode(this, 0.6, 0.2));

    this->m_layout->addExecNode(new DiagramSectionHeadersNode(this, 0.34, 0.4));
    this->m_layout->addExecNode(new DiagramSectionHeadersNode(this, 0.8, 0.2));

    this->m_layout->layoutNodes();
    this->setImplicitHeight(this->m_layout->getSize().height() + 2*getPadding());
    this->setMinWidth(this->m_layout->getMinWidth() + 2*this->m_padding);
}

DiagramScene::~DiagramScene() {
    delete m_model;
    delete m_layout;
}

void DiagramScene::paint(QPainter *painter) {
    QRect paddingRect{m_padding, m_padding,
                      static_cast<int>(width() - m_padding * 2),
                      static_cast<int>(height() - m_padding * 2)};

    int horizontalCenteringPadding = (paddingRect.width() - this->m_layout->getSize().width()) / 2;

    paddingRect.setLeft(paddingRect.left() + horizontalCenteringPadding);
    paddingRect.setRight(paddingRect.right() - horizontalCenteringPadding);

    painter->translate(paddingRect.left(), paddingRect.top());
    m_layout->paint(painter);
    painter->translate(-paddingRect.left(), -paddingRect.top());
}

void DiagramScene::setModel(DiagramModel *model) {
    if (model != this->m_model) {
        delete this->m_model;

        if (model != nullptr)
            model->setParent(this);

        this->m_model = model;
        emit modelChanged(this->m_model);
    }
}

DiagramModel *DiagramScene::getModel() const {
    return this->m_model;
}

void DiagramScene::setPadding(int padding) {
    this->m_padding = padding;
    emit paddingChanged(this->m_padding);
}

int DiagramScene::getPadding() const {
    return this->m_padding;
}

int DiagramScene::getMinWidth() const {
    return this->m_minWidth;
}

void DiagramScene::setMinWidth(int minWidth) {
    if (this->m_minWidth != minWidth) {
        this->m_minWidth = minWidth;
        emit minWidthChanged(minWidth);
    }
}
