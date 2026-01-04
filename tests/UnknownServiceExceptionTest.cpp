#include <gtest/gtest.h>
#include "exceptions/UnknownServiceException/UnknownServiceException.h"

TEST(UnknownServiceExceptionTest, MessageIncludesServiceName) {
    UnknownServiceException ex("Engine Tuning");
    std::string expected = "UnknownServiceException: Service 'Engine Tuning' not found in catalog";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(UnknownServiceExceptionTest, ExceptionIsCatchable) {
    bool caught = false;
    try {
        throw UnknownServiceException("Oil Change Premium");
    } catch (const UnknownServiceException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("UnknownServiceException"), std::string::npos);
        EXPECT_NE(std::string(e.what()).find("Oil Change Premium"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}