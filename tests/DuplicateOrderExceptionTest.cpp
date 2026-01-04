#include <gtest/gtest.h>
#include "exceptions/DuplicateOrderException/DuplicateOrderException.h"

TEST(DuplicateOrderExceptionTest, MessageContainsOrderId) {
    DuplicateOrderException ex("ORD-999");
    std::string expected = "DuplicateOrderException: Order with ID 'ORD-999' already exists";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(DuplicateOrderExceptionTest, ExceptionIsCatchable) {
    bool caught = false;
    try {
        throw DuplicateOrderException("ORD-001");
    } catch (const DuplicateOrderException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("DuplicateOrderException"), std::string::npos);
        EXPECT_NE(std::string(e.what()).find("ORD-001"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}