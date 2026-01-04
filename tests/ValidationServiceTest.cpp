#include <gtest/gtest.h>
#include "services/ValidationService/ValidationService.h"

TEST(ValidationServiceTest, IsValidName_Valid) {
    EXPECT_TRUE(ValidationService::isValidName("Ivan"));
    EXPECT_TRUE(ValidationService::isValidName("Anna-Maria"));
}

TEST(ValidationServiceTest, IsValidName_Invalid) {
    EXPECT_FALSE(ValidationService::isValidName(""));
    EXPECT_FALSE(ValidationService::isValidName("Ivan123"));
    EXPECT_FALSE(ValidationService::isValidName("123"));
}

TEST(ValidationServiceTest, IsValidPhoneFormat_Valid) {
    EXPECT_TRUE(ValidationService::isValidPhoneFormat("+7 999 123-45-67"));
    EXPECT_TRUE(ValidationService::isValidPhoneFormat("8(800)555-35-35"));
}

TEST(ValidationServiceTest, IsValidPhoneFormat_Invalid) {
    EXPECT_FALSE(ValidationService::isValidPhoneFormat(""));
    EXPECT_FALSE(ValidationService::isValidPhoneFormat("123abc"));
}

TEST(ValidationServiceTest, IsValidEmailFormat_Valid) {
    EXPECT_TRUE(ValidationService::isValidEmailFormat("test@example.com"));
    EXPECT_TRUE(ValidationService::isValidEmailFormat("user.name+tag@domain.co.uk"));
}

TEST(ValidationServiceTest, IsValidEmailFormat_Invalid) {
    EXPECT_FALSE(ValidationService::isValidEmailFormat(""));
    EXPECT_FALSE(ValidationService::isValidEmailFormat("invalid-email"));
    EXPECT_FALSE(ValidationService::isValidEmailFormat("@domain.com"));
    EXPECT_FALSE(ValidationService::isValidEmailFormat("user@"));
}

TEST(ValidationServiceTest, IsPositive) {
    EXPECT_TRUE(ValidationService::isPositive(0.01));
    EXPECT_TRUE(ValidationService::isPositive(100.0));
    EXPECT_FALSE(ValidationService::isPositive(0.0));
    EXPECT_FALSE(ValidationService::isPositive(-1.0));
}