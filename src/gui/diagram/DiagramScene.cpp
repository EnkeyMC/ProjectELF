//
// Created by MOmac on 07.03.2019.
//

#include <QPainter>

#include "gui/diagram/DiagramScene.h"
#include "gui/diagram/ProportionalDiagramLayout.h"
#include "gui/diagram/nodes/DiagramHeaderNode.h"
#include "gui/diagram/nodes/DiagramProgramHeaderTableNode.h"


DiagramScene::DiagramScene(QQuickItem *parent) : QQuickPaintedItem(parent) {
    this->setRenderTarget(QQuickPaintedItem::RenderTarget::Image);
    this->m_model = new ELFModel(std::make_shared<elf::ELF>());
    this->m_layout = new ProportionalDiagramLayout(this);
    this->setPadding(20);

    // Test nodes
    this->m_layout->addLinkNode(new DiagramHeaderNode(this, new ELFHeaderModelItem(this->m_model)));
    this->m_layout->addLinkNode(new DiagramProgramHeaderTableNode(this, new ELFProgramHeaderTableModelItem(this->m_model)));

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

void DiagramScene::setModel(ELFModel *model) {
    if (model != this->m_model) {
        if (model != nullptr)
            model->setParent(this);

        this->m_model = model;
        emit modelChanged(this->m_model);
    }
}

ELFModel *DiagramScene::getModel() const {
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