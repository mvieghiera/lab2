#include <gtest/gtest.h>
#include "models/Salary/Salary.h"

TEST(SalaryTest, ValidSalary) {
    Salary salary(50000.0, 10000.0);
    EXPECT_TRUE(salary.isValid());
    EXPECT_DOUBLE_EQ(salary.getBaseAmount(), 50000.0);
    EXPECT_DOUBLE_EQ(salary.getBonus(), 10000.0);
    EXPECT_DOUBLE_EQ(salary.getTotal(), 60000.0);
}

TEST(SalaryTest, InvalidSalary_NegativeBase) {
    Salary salary(-1000.0, 5000.0);
    EXPECT_FALSE(salary.isValid());
}

TEST(SalaryTest, ZeroBonusAllowed) {
    Salary salary(30000.0, 0.0);
    EXPECT_TRUE(salary.isValid());
    EXPECT_DOUBLE_EQ(salary.getTotal(), 30000.0);
}