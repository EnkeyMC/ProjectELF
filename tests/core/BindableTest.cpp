//
// Created by MOmac on 25.04.2019.
//

#include "gtest/gtest.h"

#include "core/Bindable.h"

TEST(BindableTest, Get_WithValue_ReturnsValue) {
    // Arrange
    Bindable<int> bindable{5};

    // Act
    int result = bindable.get();

    // Assert
    ASSERT_EQ(result, 5);
}

TEST(BindableTest, Set_Value_GetsValue) {
    // Arrange
    Bindable<int> bindable{5};

    // Act
    bindable.set(10);

    // Assert
    ASSERT_EQ(bindable.get(), 10);
}

TEST(BindableTest, OperatorEq_Value_GetsValue) {
    // Arrange
    Bindable<int> bindable{5};

    // Act
    bindable = 10;

    // Assert
    ASSERT_EQ(bindable.get(), 10);
}

TEST(BindableTest, BindTo_Unbound_ChildGetsChanged) {
    // Arrange
    Bindable<int> child{5};
    Bindable<int> parent{10};

    // Act
    child.bindTo(parent);

    // Assert
    ASSERT_EQ(child.get(), 10);
}

TEST(BindableTest, BindBidirectional_Unbound_BinderGetsChanged) {
    // Arrange
    Bindable<int> binder{5};
    Bindable<int> other{10};

    // Act
    binder.bindBidirectional(other);

    // Assert
    ASSERT_EQ(binder.get(), 10);
}

TEST(BindableTest, Set_Bound_ChildGetsChanged) {
    // Arrange
    Bindable<int> child{5};
    Bindable<int> parent{5};
    child.bindTo(parent);

    // Act
    parent.set(10);

    // Assert
    ASSERT_EQ(child.get(), 10);
}

TEST(BindableTest, Set_BidirectionalyBound_BinderGetsChanged) {
    // Arrange
    Bindable<int> binder{5};
    Bindable<int> other{5};
    binder.bindBidirectional(other);

    // Act
    other.set(10);

    // Assert
    ASSERT_EQ(binder.get(), 10);
}

TEST(BindableTest, Set_BidirectionalyBound_OtherGetsChanged) {
    // Arrange
    Bindable<int> binder{5};
    Bindable<int> other{5};
    binder.bindBidirectional(other);

    // Act
    binder.set(10);

    // Assert
    ASSERT_EQ(other.get(), 10);
}

TEST(BindableTest, OperatorEq_Bound_ChildGetsChanged) {
    // Arrange
    Bindable<int> child{5};
    Bindable<int> parent{5};
    child.bindTo(parent);

    // Act
    parent = 10;

    // Assert
    ASSERT_EQ(child.get(), 10);
}

TEST(BindableTest, OperatorEq_BidirectionalyBound_BinderGetsChanged) {
    // Arrange
    Bindable<int> binder{5};
    Bindable<int> other{5};
    binder.bindBidirectional(other);

    // Act
    other = 10;

    // Assert
    ASSERT_EQ(binder.get(), 10);
}

TEST(BindableTest, OperatorEq_BidirectionalyBound_OtherGetsChanged) {
    // Arrange
    Bindable<int> binder{5};
    Bindable<int> other{5};
    binder.bindBidirectional(other);

    // Act
    binder = 10;

    // Assert
    ASSERT_EQ(other.get(), 10);
}
