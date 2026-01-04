#include <gtest/gtest.h>
#include "exceptions/FileWriteException/FileWriteException.h"

TEST(FileWriteExceptionTest, MessageContainsFilename) {
    FileWriteException ex("backup.dat");
    std::string expected = "FileWriteException: Unable to write to file 'backup.dat'";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(FileWriteExceptionTest, ExceptionIsCatchable) {
    bool caught = false;
    try {
        throw FileWriteException("orders.csv");
    } catch (const FileWriteException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("FileWriteException"), std::string::npos);
        EXPECT_NE(std::string(e.what()).find("orders.csv"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}