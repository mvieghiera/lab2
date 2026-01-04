#include <gtest/gtest.h>
#include "exceptions/InvalidPartException/InvalidPartException.h"

TEST(InvalidPartExceptionTest, MessageContainsCorrectPrefix) {
    InvalidPartException ex("Price must be positive");
    std::string expected = "InvalidPartException: Price must be positive";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(InvalidPartExceptionTest, ExceptionIsCatchable) {
    bool caught = false;
    try {
        throw InvalidPartException("Empty part number");
    } catch (const InvalidPartException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("InvalidPartException"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}