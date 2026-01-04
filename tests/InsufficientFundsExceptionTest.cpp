#include <gtest/gtest.h>
#include "exceptions/InsufficientFundsException/InsufficientFundsException.h"

TEST(InsufficientFundsExceptionTest, MessageShowsAmounts) {
    InsufficientFundsException ex(15000.50, 10000.00);
    std::string msg(ex.what());
    EXPECT_NE(msg.find("InsufficientFundsException"), std::string::npos);
    EXPECT_NE(msg.find("15000.50"), std::string::npos);
    EXPECT_NE(msg.find("10000.00"), std::string::npos);
}

TEST(InsufficientFundsExceptionTest, ExceptionIsCatchable) {
    bool caught = false;
    try {
        throw InsufficientFundsException(5000.0, 3000.0);
    } catch (const InsufficientFundsException& e) {
        caught = true;
        EXPECT_STREQ(e.what(),
            "InsufficientFundsException: Required 5000.00, but only 3000.00 available");
    }
    EXPECT_TRUE(caught);
}