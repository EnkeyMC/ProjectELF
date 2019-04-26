//
// Created by MOmac on 15.04.2019.
//

#ifndef PROJECTELF_QUADTREE_H
#define PROJECTELF_QUADTREE_H

#include <array>
#include <vector>
#include <QLine>

template <typename TData>
class VerticalBinaryTree {
public:
    explicit VerticalBinaryTree(QLine verticalBounds = QLine(), int level = 0);

    ~VerticalBinaryTree();

    void insert(TData* data);

    std::vector<TData*> getContaining(QPoint point) const;

    void clear();

    void setBounds(QLine bounds);

    QLine getBounds() const;

private:

    void split();
    void propagateItems();

    int getIndex(TData* data) const;

    bool shouldSplit() const;

    void getContainingRecursive(QPoint point, std::vector<TData*> &outItems) const;

    bool contains(QLine bounds) const;
    bool contains(QRect bounds) const;

    const int TOP = 0;
    const int BOTTOM = 1;

    const int MAX_ITEMS = 5;
    const int MAX_LEVEL = 10;

    QLine verticalBounds;
    int level;

    std::array<VerticalBinaryTree *, 2> nodes;
    std::vector<TData*> items;
};


template <typename TData>
VerticalBinaryTree<TData>::VerticalBinaryTree(QLine verticalBounds, int level)
        : verticalBounds(verticalBounds), level(level)
{
    for (int i = 0; i < nodes.size(); i++)
        nodes[i] = nullptr;
}

template <typename TData>
VerticalBinaryTree<TData>::~VerticalBinaryTree() {
    for (auto node : nodes)
        delete node;
}

template <typename TData>
void VerticalBinaryTree<TData>::split() {
    int halfHeight = this->verticalBounds.dy() / 2;
    auto topBounds = QLine(verticalBounds.p1(), verticalBounds.p2() - QPoint(0, halfHeight));
    auto bottomBounds = QLine(verticalBounds.p1() + QPoint(0, halfHeight), verticalBounds.p2());
    nodes[TOP] = new VerticalBinaryTree(topBounds, this->level + 1);
    nodes[BOTTOM] = new VerticalBinaryTree(bottomBounds, this->level + 1);
}

template <typename TData>
void VerticalBinaryTree<TData>::propagateItems() {
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
int VerticalBinaryTree<TData>::getIndex(TData *data) const {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->contains(data->getBounds()))
            return i;
    }
    return -1;
}

template <typename TData>
void VerticalBinaryTree<TData>::getContainingRecursive(QPoint point, std::vector<TData *> &outItems) const {
    for (auto item : items) {
        if (item->contains(point))
            outItems.push_back(item);
    }

    for (auto node : nodes) {
        if (node != nullptr)
            node->getContainingRecursive(point, outItems);
    }
}

template <typename TData>
void VerticalBinaryTree<TData>::insert(TData *data) {
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

template <typename TData>
bool VerticalBinaryTree<TData>::shouldSplit() const {
    return items.size() > MAX_ITEMS && level < MAX_LEVEL;
}

template <typename TData>
std::vector<TData *> VerticalBinaryTree<TData>::getContaining(QPoint point) const {
    std::vector<TData *> retItems;
    this->getContainingRecursive(point, retItems);
    return retItems;
}

template <typename TData>
void VerticalBinaryTree<TData>::clear() {
    items.erase(items.begin(), items.end());

    for (int i = 0; i < nodes.size(); i++) {
        delete nodes[i];
        nodes[i] = nullptr;
    }
}

template <typename TData>
void VerticalBinaryTree<TData>::setBounds(QLine bounds) {
    this->verticalBounds = bounds;
}

template <typename TData>
QLine VerticalBinaryTree<TData>::getBounds() const {
    return this->verticalBounds;
}

template <typename TData>
bool VerticalBinaryTree<TData>::contains(QLine bounds) const {
    return this->verticalBounds.y1() <= bounds.y1() && this->verticalBounds.y2() >= bounds.y2();
}

template <typename TData>
bool VerticalBinaryTree<TData>::contains(QRect bounds) const {
    return this->verticalBounds.y1() <= bounds.top() && this->verticalBounds.y2() >= bounds.bottom();
}


#endif //PROJECTELF_QUADTREE_H
