#include <gtest/gtest.h>
#include "exceptions/InvalidServiceException/InvalidServiceException.h"

TEST(InvalidServiceExceptionTest, MessageFormatIsCorrect) {
    InvalidServiceException ex("Service price must be > 0");
    std::string expected = "InvalidServiceException: Service price must be > 0";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(InvalidServiceExceptionTest, ExceptionCanBeCaught) {
    bool caught = false;
    try {
        throw InvalidServiceException("Empty service name");
    } catch (const InvalidServiceException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("InvalidServiceException"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}