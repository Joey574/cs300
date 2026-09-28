#include <gtest/gtest.h>
#include <stdexcept>

#include "clock.hpp"

TEST(ClockConstructorTest, DefaultConstructor) {
    Clock clock;
    EXPECT_EQ(clock.Hour(), 0);
    EXPECT_EQ(clock.Minute(), 0);
}

TEST(ClockConstructorTest, ParameterizedConstructor) {
    Clock clock(23, 12);
    EXPECT_EQ(clock.Hour(), 23);
    EXPECT_EQ(clock.Minute(), 12);
}

TEST(ClockContrctorTest, BadArguments) {
    EXPECT_THROW(Clock(-1, -20), std::invalid_argument);
}

TEST(AdvanceClockTest, SimpleAdvance) {
    Clock clock(12, 30);
    clock.Advance(30);

    EXPECT_EQ(clock.Hour(), 13);
    EXPECT_EQ(clock.Minute(), 0);
}

TEST(AdvanceClockTest, LargeAdvance) {
    Clock clock;
    clock.Advance(3320);

    EXPECT_EQ(clock.Hour(), 7);
    EXPECT_EQ(clock.Minute(), 20);
}

TEST(AdvanceClockTest, NegativeAdvance) {
    Clock clock(12, 00);
    clock.Advance(-138);

    EXPECT_EQ(clock.Hour(), 9);
    EXPECT_EQ(clock.Minute(), 42);
}

TEST(AdvanceClockTest, HolisticTest) {
    Clock clock;

    clock.Advance(27);
    EXPECT_EQ(clock.Hour(), 0);
    EXPECT_EQ(clock.Minute(), 27);

    clock.Advance(42);
    EXPECT_EQ(clock.Hour(), 1);
    EXPECT_EQ(clock.Minute(), 9);

    clock.Advance(170);
    EXPECT_EQ(clock.Hour(), 3);
    EXPECT_EQ(clock.Minute(), 59);

    clock.Advance(1);
    EXPECT_EQ(clock.Hour(), 4);
    EXPECT_EQ(clock.Minute(), 0);

    clock.Advance(-1);
    EXPECT_EQ(clock.Hour(), 3);
    EXPECT_EQ(clock.Minute(), 59);

    clock.Advance(722);
    EXPECT_EQ(clock.Hour(), 16);
    EXPECT_EQ(clock.Minute(), 1);

    clock.Advance(478);
    EXPECT_EQ(clock.Hour(), 23);
    EXPECT_EQ(clock.Minute(), 59);

    clock.Advance(1);
    EXPECT_EQ(clock.Hour(), 0);
    EXPECT_EQ(clock.Minute(), 0);
}
