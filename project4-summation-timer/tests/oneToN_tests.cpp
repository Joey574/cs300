#include <gtest/gtest.h>

#include "oneToN.hpp"

void testSummations(unsigned long long (*sum)(unsigned long long)) {
    EXPECT_EQ(sum(10), 55);
    EXPECT_EQ(sum(9), 45);
    EXPECT_EQ(sum(8), 36);
    EXPECT_EQ(sum(7), 28);
    EXPECT_EQ(sum(6), 21);
    EXPECT_EQ(sum(5), 15);
    EXPECT_EQ(sum(4), 10);
    EXPECT_EQ(sum(3), 6);
    EXPECT_EQ(sum(2), 3);
    EXPECT_EQ(sum(1), 1);
    EXPECT_EQ(sum(0), 0);

    // large n tests
    EXPECT_EQ(sum(1000), 500500);
    EXPECT_EQ(sum(10000), 50005000);

    // weird n tests
    EXPECT_EQ(sum(7539), 28422030);
}

TEST(ConstantSummation, BasicSummations) {
    testSummations(OneToNSumCalculator::sumConstant);
}

TEST(LinearSummation, BasicSummations) {
    testSummations(OneToNSumCalculator::sumLinear);
}

TEST(QuadraticSummation, BasicSummations) {
    testSummations(OneToNSumCalculator::sumQuadratic);
}
