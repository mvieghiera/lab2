#include <gtest/gtest.h>
#include "exceptions/FileReadException/FileReadException.h"

TEST(FileReadExceptionTest, MessageContainsFilename) {
    FileReadException ex("data.txt");
    std::string expected = "FileReadException: Unable to read file 'data.txt'";
    EXPECT_EQ(std::string(ex.what()), expected);
}

TEST(FileReadExceptionTest, ExceptionIsCatchable) {
    bool caught = false;
    try {
        throw FileReadException("config.ini");
    } catch (const FileReadException& e) {
        caught = true;
        EXPECT_NE(std::string(e.what()).find("FileReadException"), std::string::npos);
        EXPECT_NE(std::string(e.what()).find("config.ini"), std::string::npos);
    }
    EXPECT_TRUE(caught);
}