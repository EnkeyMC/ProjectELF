//
// Created by MOmac on 16.04.2019.
//

#include <QRect>

#include "gtest/gtest.h"
#include "core/VerticalBinaryTree.h"
#include "core/IVerticalBinaryTreeNode.h"


class VerticalBinaryTreeNodeDummy : virtual public IVerticalBinaryTreeNode {
public:
    explicit VerticalBinaryTreeNodeDummy(QRect bounds) : bounds(bounds) {}

    QRect getBounds() const override {
        return bounds;
    }

    bool contains(const QPoint &point) const override {
        return bounds.contains(point);
    }

protected:
    QRect bounds;
};

class EmptyVerticalBinaryTreeTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        tree = new VerticalBinaryTree<VerticalBinaryTreeNodeDummy>(QLine(0, 0, 0, 500));
    }

    void TearDown() override {
        delete tree;
    }

    VerticalBinaryTree<VerticalBinaryTreeNodeDummy> *tree = nullptr;
};

TEST_F(EmptyVerticalBinaryTreeTestFixture, GetContaining_EmptyTree_ReturnsEmpty) {
    // Arrange
    QPoint point{250, 250};

    // Act
    auto items = tree->getContaining(point);

    // Assert
    ASSERT_TRUE(items.empty());
}

TEST_F(EmptyVerticalBinaryTreeTestFixture, Insert_EmptyTree_DoesNotThrow) {
    // Arrange
    VerticalBinaryTreeNodeDummy node{QRect(0, 0, 100, 100)};

    // Act & Assert
    ASSERT_NO_THROW(tree->insert(&node));
}

TEST_F(EmptyVerticalBinaryTreeTestFixture, SetAndGetBounds_EmptyTree_ReturnsBounds) {
    // Arrange
    QLine bounds{0, 0, 0, 100};

    // Act
    tree->setBounds(bounds);
    QLine result = tree->getBounds();

    // Assert
    ASSERT_EQ(bounds, result);
}

TEST_F(EmptyVerticalBinaryTreeTestFixture, Clear_EmptyTree_DoesNotThrow) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(tree->clear());
}

#define INSERT_NODE(x, y, width, height) node = new VerticalBinaryTreeNodeDummy(QRect{x, y, width, height}); \
            nodes.push_back(node); \
            tree->insert(node);

class FilledVerticalBinaryTreeTestFixture : public EmptyVerticalBinaryTreeTestFixture {
protected:
    void SetUp() override {
        EmptyVerticalBinaryTreeTestFixture::SetUp();

        VerticalBinaryTreeNodeDummy* node;
        INSERT_NODE(0, 0, 1000, 10);
        INSERT_NODE(0, 10, 1000, 10);
        INSERT_NODE(0, 20, 500, 10);
        INSERT_NODE(0, 40, 1000, 30);
        INSERT_NODE(0, 70, 30, 430);
        INSERT_NODE(0, 100, 20, 20);
        INSERT_NODE(500, 300, 500, 200);
        INSERT_NODE(500, 300, 500, 20);
        INSERT_NODE(500, 320, 500, 40);
        INSERT_NODE(500, 340, 500, 40);
        INSERT_NODE(450, 380, 400, 120);
    }

    void TearDown() override {
        EmptyVerticalBinaryTreeTestFixture::TearDown();
        for (auto node : nodes)
            delete node;
    }

    std::vector<VerticalBinaryTreeNodeDummy *> nodes;
};

TEST_F(FilledVerticalBinaryTreeTestFixture, GetContaining_EmptySpace_ReturnsEmpty) {
    // Arrange
    QPoint point{400, 150};

    // Act
    auto items = tree->getContaining(point);

    // Assert
    ASSERT_TRUE(items.empty());
}

TEST_F(FilledVerticalBinaryTreeTestFixture, GetContaining_SingleItem_ReturnsOne) {
    // Arrange
    QPoint point{30, 45};

    // Act
    auto items = tree->getContaining(point);

    // Assert
    ASSERT_EQ(items.size(), 1);
    ASSERT_EQ(items[0]->getBounds(), nodes[3]->getBounds());
}

TEST_F(FilledVerticalBinaryTreeTestFixture, GetContaining_Overlaping_ReturnsThree) {
    // Arrange
    QPoint point{700, 345};

    // Act
    auto items = tree->getContaining(point);

    // Assert
    ASSERT_EQ(items.size(), 3);
}
