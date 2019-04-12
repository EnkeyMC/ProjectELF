//
// Created by MOmac on 07.03.2019.
//

#include <QPainter>

#include "gui/diagram/DiagramScene.h"
#include "gui/diagram/ProportionalDiagramLayout.h"
#include "gui/diagram/nodes/DiagramHeaderNode.h"
#include "gui/diagram/nodes/DiagramProgramHeaderTableNode.h"
#include "gui/diagram/nodes/DiagramSectionHeaderTableNode.h"


DiagramScene::DiagramScene(QQuickItem *parent) : QQuickPaintedItem(parent), model(nullptr) {
    connect(this, &DiagramScene::modelChanged, this, &DiagramScene::onModelChanged);

    this->setRenderTarget(QQuickPaintedItem::RenderTarget::Image);
    this->layout = new ProportionalDiagramLayout(this);
    this->setPadding(20);

    this->layout->layoutNodes();
    this->setImplicitHeight(this->layout->getSize().height() + 2*getPadding());
    this->setMinWidth(this->layout->getMinWidth() + 2*this->padding);
}

DiagramScene::~DiagramScene() {
    delete layout;
}

void DiagramScene::paint(QPainter *painter) {
    QRect paddingRect{padding, padding,
                      static_cast<int>(width() - padding * 2),
                      static_cast<int>(height() - padding * 2)};

    int horizontalCenteringPadding = (paddingRect.width() - this->layout->getSize().width()) / 2;

    paddingRect.setLeft(paddingRect.left() + horizontalCenteringPadding);
    paddingRect.setRight(paddingRect.right() - horizontalCenteringPadding);

    painter->translate(paddingRect.left(), paddingRect.top());
    layout->paint(painter);
    painter->translate(-paddingRect.left(), -paddingRect.top());
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

    if (this->model == nullptr)
        return;

    auto header = this->model->getHeader();
    if (header == nullptr)
        return;

    this->layout->addLinkNode(new DiagramHeaderNode(this, header));

    auto sectionHeaderTable = header->getSectionHeaderTable();
    if (sectionHeaderTable != nullptr) {
        this->layout->addLinkNode(new DiagramSectionHeaderTableNode(this, sectionHeaderTable));

        for (auto sectionHeader : sectionHeaderTable->getSectionHeaders()) {
//            this->layout->addLinkNode()
        }
    }

    auto programHeaderTable = header->getProgramHeaderTable();
    if (programHeaderTable != nullptr) {
        this->layout->addExecNode(new DiagramProgramHeaderTableNode(this, programHeaderTable));
    }
}
