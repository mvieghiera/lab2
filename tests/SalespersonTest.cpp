#include <gtest/gtest.h>
#include "models/Salesperson/Salesperson.h"
#include "models/Address/Address.h"

TEST(SalespersonTest, ValidSalesperson) {
    Address addr("Vladivostok", "Admirala", "10");
    Salesperson sp("Elena", "Sales", "+7333", addr, 0.1);

    EXPECT_TRUE(sp.isValid());
    EXPECT_DOUBLE_EQ(sp.getCommissionRate(), 0.1);
}

TEST(SalespersonTest, InvalidCommissionRate_TooHigh) {
    Address addr("Omsk", "Gorkogo", "5");
    Salesperson sp("Igor", "Agent", "+7222", addr, 1.5);
    EXPECT_FALSE(sp.isValid());
}

TEST(SalespersonTest, InvalidCommissionRate_Negative) {
    Address addr("Novosibirsk", "Krasny", "7");
    Salesperson sp("Dmitry", "Seller", "+7111", addr, -0.1);
    EXPECT_FALSE(sp.isValid());
}