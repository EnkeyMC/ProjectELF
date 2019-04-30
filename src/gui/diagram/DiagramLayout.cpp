//
// Created by MOmac on 10.03.2019.
//

#include <include/gui/diagram/DiagramLayout.h>
#include <algorithm>

#include "gui/diagram/DiagramLayout.h"
#include "gui/diagram/DiagramScene.h"

DiagramLayout::DiagramLayout(DiagramScene *diagram) : QObject(diagram) {
    this->diagram = diagram;
    this->minWidth = 0;

    connect(this, &DiagramLayout::zOrderChanged, diagram, &DiagramScene::repaint);
}

void DiagramLayout::addNode(DiagramNode *node) {
    if (node->getViewSide() == DiagramNode::RIGHT)
        this->execColumnSortedNodes.emplace(node, nodesZOrdered.size());
    else
        this->linkColumnSortedNodes.emplace(node, nodesZOrdered.size());
    nodesZOrdered.push_back(node);
}

void DiagramLayout::clearNodes()
{
    for (auto node : linkColumnSortedNodes)
        delete node.first;
    for (auto node : execColumnSortedNodes)
        delete node.first;

    linkColumnSortedNodes.clear();
    execColumnSortedNodes.clear();
    nodesZOrdered.clear();
}

void DiagramLayout::forEachLinkNode(const NodeCallback &callback) {
    for (auto node : linkColumnSortedNodes)
        callback(*node.first);
}

void DiagramLayout::forEachExecNode(const NodeCallback &callback) {
    for (auto node : execColumnSortedNodes)
        callback(*node.first);
}

void DiagramLayout::forEachNode(const NodeCallback &callback) {
    forEachLinkNode(callback);
    forEachExecNode(callback);
}

QSize DiagramLayout::getSize() const {
    return size;
}

int DiagramLayout::getMinWidth() const {
    return minWidth;
}

void DiagramLayout::layoutNodes() {
    emit layoutChanged();
}

const DiagramLayout::SortedNodesType &DiagramLayout::getLinkColumnSortedNodes() const {
    return linkColumnSortedNodes;
}

const DiagramLayout::SortedNodesType &DiagramLayout::getExecColumnSortedNodes() const {
    return execColumnSortedNodes;
}

void DiagramLayout::pushToFront(DiagramNode *node) {
    auto nodeIterator = getNodeIterator(node);
    if (nodeIterator == getEndIterator(node->getViewSide()))
        return;

    nodesZOrdered.erase(nodesZOrdered.begin() + nodeIterator->second);
    for (int i = nodeIterator->second; i < nodesZOrdered.size(); i++) {
        getNodeIterator(nodesZOrdered.at(i))->second = i;
    }
    nodeIterator->second = nodesZOrdered.size();
    nodesZOrdered.push_back(node);

    emit zOrderChanged();
}

DiagramLayout::SortedNodesType::iterator DiagramLayout::getNodeIterator(DiagramNode *node) {
    if (node->getViewSide() == DiagramNode::RIGHT) {
        return findNode(execColumnSortedNodes, node);
    } else {
        return findNode(linkColumnSortedNodes, node);
    }
}

DiagramLayout::SortedNodesType::const_iterator DiagramLayout::getNodeIterator(DiagramNode *node) const {
    if (node->getViewSide() == DiagramNode::RIGHT) {
        return findNode(execColumnSortedNodes, node);
    } else {
        return findNode(linkColumnSortedNodes, node);
    }
}

std::function<bool(const DiagramLayout::SortedNodesType::value_type &)>
DiagramLayout::getPairEqualityComparer(DiagramNode *node) const {
    return [=](const DiagramLayout::SortedNodesType::value_type &pair) -> bool {
        return pair.first == node;
    };
}

DiagramLayout::SortedNodesType::iterator
DiagramLayout::findNode(DiagramLayout::SortedNodesType &nodes, DiagramNode *node) {
    auto it = std::find_if(nodes.lower_bound(node), nodes.upper_bound(node), getPairEqualityComparer(node));
    if (it == nodes.upper_bound(node))
        return nodes.end();
    return it;
}

DiagramLayout::SortedNodesType::const_iterator
DiagramLayout::findNode(const DiagramLayout::SortedNodesType &nodes, DiagramNode *node) const {
    auto it = std::find_if(nodes.lower_bound(node), nodes.upper_bound(node), getPairEqualityComparer(node));
    if (it == nodes.upper_bound(node))
        return nodes.cend();
    return it;
}

DiagramLayout::SortedNodesType::iterator DiagramLayout::getEndIterator(DiagramNode::ViewSide side) {
    return side == DiagramNode::RIGHT ? execColumnSortedNodes.end() : linkColumnSortedNodes.end();
}

DiagramLayout::SortedNodesType::const_iterator DiagramLayout::getEndIterator(DiagramNode::ViewSide side) const {
    return side == DiagramNode::RIGHT ? execColumnSortedNodes.cend() : linkColumnSortedNodes.cend();
}

const std::deque<DiagramNode *> &DiagramLayout::getNodesZOrdered() const {
    return nodesZOrdered;
}
