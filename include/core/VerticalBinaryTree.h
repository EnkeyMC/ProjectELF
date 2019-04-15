//
// Created by MOmac on 15.04.2019.
//

#ifndef PROJECTELF_QUADTREE_H
#define PROJECTELF_QUADTREE_H

#include <array>
#include <vector>
#include <QRect>

template <typename TData>
class VerticalBinaryTree {
    explicit VerticalBinaryTree(QRect bounds, int level = 0);

    ~VerticalBinaryTree();

    void insert(TData* data);

    std::vector<TData*> getContaining(QPoint point) const;

    void clear();

    void setBounds(QRect bounds);

    QRect getBounds() const;

private:
    void split();

    void propagateItems();

    int getIndex(TData* data) const;

    bool shouldSplit() const;

    void getContainingRecursive(QPoint point, std::vector<TData*> &outItems) const;

    const int TOP = 0;
    const int BOTTOM = 1;

    const int MAX_ITEMS = 5;
    const int MAX_LEVEL = 10;

    QRect bounds;
    int level;

    std::array<VerticalBinaryTree *, 2> nodes;
    std::vector<TData*> items;
};

VerticalBinaryTree::VerticalBinaryTree(QRect bounds, int level)
        : bounds(bounds), level(level)
{
    for (int i = 0; i < nodes.size(); i++)
        nodes[i] = nullptr;
}

VerticalBinaryTree::~VerticalBinaryTree() {
    for (auto node : nodes)
        delete node;
}

void VerticalBinaryTree::split() {
    int halfHeight = this->bounds.height() / 2;
    nodes[TOP] = new VerticalBinaryTree(bounds.adjusted(0, 0, 0, -halfHeight), this->level + 1);
    nodes[BOTTOM] = new VerticalBinaryTree(bounds.adjusted(0, halfHeight, 0, 0), this->level + 1);
}

void VerticalBinaryTree::propagateItems() {
    for (auto it = this->items.begin(); it != this->items.end(); ) {
        int index = this->getIndex(*it);
        if (index != -1) {
            nodes[index]->insert(*it);
            it = this->items.erase(it);
        } else {
            ++it;
        }
    }
}

template <typename TData>
int VerticalBinaryTree::getIndex(TData *data) const {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->getBounds().contains(data->getBounds()))
            return i;
    }
    return -1;
}

template <typename TData>
void VerticalBinaryTree::getContainingRecursive(QPoint point, std::vector<TData *> &outItems) const {
    for (auto item : items) {
        if (item->contains(point))
            outItems.push_back(item);
    }
}

template <typename TData>
void VerticalBinaryTree::insert(TData *data) {
    if (nodes[TOP] != nullptr) {
        int index = this->getIndex(data);
        if (index != -1) {
            nodes[index]->insert(data);
            return;
        }
    }

    items.push_back(data);

    if (this->shouldSplit()) {
        this->split();
        this->propagateItems();
    }
}

bool VerticalBinaryTree::shouldSplit() const {
    return items.size() > MAX_ITEMS && level < MAX_LEVEL;
}

template <typename TData>
std::vector<TData *> VerticalBinaryTree::getContaining(QPoint point) const {
    std::vector<TData *> retItems;
    this->getContainingRecursive(point, retItems);
    return retItems;
}

void VerticalBinaryTree::clear() {
    items.erase(items.begin(), items.end());

    for (int i = 0; i < nodes.size(); i++) {
        delete nodes[i];
        nodes[i] = nullptr;
    }
}

void VerticalBinaryTree::setBounds(QRect bounds) {
    this->bounds = bounds;
}

QRect VerticalBinaryTree::getBounds() const {
    return this->bounds;
}


#endif //PROJECTELF_QUADTREE_H
