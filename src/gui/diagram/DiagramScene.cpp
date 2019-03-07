//
// Created by MOmac on 07.03.2019.
//

#include "gui/diagram/DiagramScene.h"

DiagramScene::DiagramScene(QQuickItem *parent) : QQuickPaintedItem(parent) {
    this->setRenderTarget(QQuickPaintedItem::RenderTarget::Image);
    this->m_model = nullptr;
}

void DiagramScene::paint(QPainter *painter) {

}

void DiagramScene::setModel(DiagramModel *model) {
    this->m_model = model;
    emit modelChanged();
    qDebug() << "Model changed";
}

DiagramModel *DiagramScene::getModel() const {
    return this->m_model;
}
