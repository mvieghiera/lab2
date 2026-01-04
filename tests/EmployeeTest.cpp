#include <gtest/gtest.h>
#include "models/Employee/Employee.h"
#include "models/Address/Address.h"

TEST(EmployeeTest, ValidEmployee) {
    Address addr("Novosibirsk", "Krasny", "25");
    Employee emp("Sergey Ivanov", "Master", "+7 987 654-32-10", addr);
    EXPECT_TRUE(emp.isValid());
    EXPECT_EQ(emp.getPosition(), "Master");
    EXPECT_EQ(emp.getAddress().getCity(), "Novosibirsk");
}

TEST(EmployeeTest, InvalidEmployee_EmptyPosition) {
    Address addr("Omsk", "Lenina", "5");
    Employee emp("Alexey", "", "+79991112233", addr);
    EXPECT_FALSE(emp.isValid());
}