#include <gtest/gtest.h>

#include "creditCard.hpp"
#include "transaction.hpp"

TEST(CreditCard, DefaultConstructor) {
    CreditCardAccount c;
    EXPECT_TRUE(c.getTransactions().empty());
    EXPECT_EQ(c.getBalance(), 0);
}

TEST(CreditCard, CopyConstructor) {
    CreditCardAccount c1;
    c1.credit(10.0);
    EXPECT_EQ(c1.getBalance(), 10.0);

    auto c2(c1);
    EXPECT_EQ(c2.getBalance(), 10.0);

    c2.purchase(10.0);
    EXPECT_EQ(c2.getBalance(), 0.0);
    EXPECT_EQ(c1.getBalance(), 10.0);
}

TEST(CreditCard, AssignmentOperator) {
    CreditCardAccount c1;
    c1.credit(10.0);
    EXPECT_EQ(c1.getBalance(), 10.0);

    auto c2 = c1;
    EXPECT_EQ(c2.getBalance(), 10.0);

    c2.purchase(10.0);
    EXPECT_EQ(c2.getBalance(), 0.0);
    EXPECT_EQ(c1.getBalance(), 10.0);
}

TEST(CreditCard, MultipleTransactions) {
    CreditCardAccount c;
    c.purchase(10.0);
    EXPECT_EQ(c.getBalance(), -10.0);

    c.credit(20.0);
    EXPECT_EQ(c.getBalance(), 10.0);
}

TEST(CreditCard, ToVector) {
    CreditCardAccount c;
    EXPECT_TRUE(c.getTransactions().empty());

    c.purchase(1.0);
    EXPECT_EQ(c.getTransactions().size(), 1);
    EXPECT_TRUE(c.getTransactions()[0].getAmount() == 1.0);
    EXPECT_TRUE(c.getTransactions()[0].getType() == Transaction::Type::Purchase);

    c.credit(5.0);
    EXPECT_EQ(c.getTransactions().size(), 2);
    EXPECT_TRUE(c.getTransactions()[1].getAmount() == 5.0);
    EXPECT_TRUE(c.getTransactions()[1].getType() == Transaction::Type::Credit);

}
