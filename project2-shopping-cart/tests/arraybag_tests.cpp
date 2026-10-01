#include <gtest/gtest.h>

#include "arraybag.hpp"

TEST(ArrayBagConstructorTest, DefaultConstructor) {
    ResizeableArrayBag<int> bag;
    EXPECT_EQ(bag.Size(), 0);
    EXPECT_EQ(bag.Capacity(), 0);
}

TEST(ArrayBagConstructorTest, ParameterConstructor) {
    ResizeableArrayBag<int> bag(10);
    EXPECT_EQ(bag.Size(), 0);
    EXPECT_EQ(bag.Capacity(), 10);
}

TEST(ArrayBagPushTest, BlackBoxBasicPush) {
    ResizeableArrayBag<int> bag(10);
    bag.Push(0);
    bag.Push(1);
    bag.Push(2);
    bag.Push(3);
    bag.Push(4);
    bag.Push(5);
    bag.Push(6);
    bag.Push(7);
    bag.Push(8);
    bag.Push(9);
    bag.Push(10);
}
