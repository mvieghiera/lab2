#include <gtest/gtest.h>
#include "exceptions/InvalidOrderException/InvalidOrderException.h"

TEST(InvalidOrderExceptionTest, MessageFormat) {
    InvalidOrderException ex("Missing services");
    std::string expected = "InvalidOrderException: Missing services";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(InvalidOrderExceptionTest, ExceptionCaught) {
    bool caught = false;
    try {
        throw InvalidOrderException("Invalid car data");
    } catch (const InvalidOrderException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("InvalidOrderException"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}