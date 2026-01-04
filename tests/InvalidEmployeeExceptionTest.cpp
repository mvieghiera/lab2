#include <gtest/gtest.h>
#include "exceptions/InvalidEmployeeException/InvalidEmployeeException.h"

TEST(InvalidEmployeeExceptionTest, MessageContainsPrefix) {
    InvalidEmployeeException ex("Position is empty");
    std::string msg(ex.what());
    EXPECT_NE(msg.find("InvalidEmployeeException: Position is empty"), std::string::npos);
}

TEST(InvalidEmployeeExceptionTest, CatchAndHandle) {
    bool caught = false;
    try {
        throw InvalidEmployeeException("Invalid phone format");
    } catch (const InvalidEmployeeException& e) {
        caught = true;
        EXPECT_STREQ(e.what(), "InvalidEmployeeException: Invalid phone format");
    }
    EXPECT_TRUE(caught);
}