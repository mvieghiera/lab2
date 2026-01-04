#include <gtest/gtest.h>
#include "exceptions/DatabaseConnectionException/DatabaseConnectionException.h"

TEST(DatabaseConnectionExceptionTest, MessageContainsDetails) {
    DatabaseConnectionException ex("Timeout expired");
    std::string expected = "DatabaseConnectionException: Failed to connect to database. Details: Timeout expired";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(DatabaseConnectionExceptionTest, ExceptionCanBeCaught) {
    bool caught = false;
    try {
        throw DatabaseConnectionException("Access denied");
    } catch (const DatabaseConnectionException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("DatabaseConnectionException"), std::string::npos);
        EXPECT_NE(std::string(e.what()).find("Access denied"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}