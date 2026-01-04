#include <gtest/gtest.h>
#include "exceptions/InvalidClientException/InvalidClientException.h"

TEST(InvalidClientExceptionTest, ThrowsCorrectMessage) {
    std::string errorMsg = "Client name is empty";
    InvalidClientException exception(errorMsg);

    std::string expected = "InvalidClientException: " + errorMsg;
    EXPECT_STREQ(exception.what(), expected.c_str());
}

TEST(InvalidClientExceptionTest, CatchException) {
    bool caught = false;
    try {
        throw InvalidClientException("Test error");
    } catch (const InvalidClientException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("InvalidClientException"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}