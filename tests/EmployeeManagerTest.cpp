#include <gtest/gtest.h>
#include "managers/EmployeeManager/EmployeeManager.h"
#include "models/Address/Address.h"

TEST(EmployeeManagerTest, AddValidEmployee) {
    EmployeeManager manager;
    Address addr("Moscow", "Lenina", "10");
    Employee emp("Ivan", "Master", "+79991234567", addr);

    manager.addEmployee(emp);
    EXPECT_EQ(manager.getAllEmployees().size(), 1);
    EXPECT_TRUE(manager.hasEmployee("Ivan"));
}

TEST(EmployeeManagerTest, IgnoreDuplicateEmployee) {
    EmployeeManager manager;
    Address addr("SPb", "Nevsky", "5");
    Employee emp("Anna", "Receptionist", "+79876543210", addr);

    manager.addEmployee(emp);
    manager.addEmployee(emp); // дубликат
    EXPECT_EQ(manager.getAllEmployees().size(), 1);
}

TEST(EmployeeManagerTest, FindExistingEmployee) {
    EmployeeManager manager;
    Address addr("Kazan", "Bauman", "15");
    Employee emp("Sergey", "Mechanic", "+79001234567", addr);
    manager.addEmployee(emp);

    const Employee* found = manager.findEmployeeByName("Sergey");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getPosition(), "Mechanic");
}

TEST(EmployeeManagerTest, FindNonExistingEmployee) {
    EmployeeManager manager;
    const Employee* found = manager.findEmployeeByName("Unknown");
    EXPECT_EQ(found, nullptr);
}

TEST(EmployeeManagerTest, IgnoreInvalidEmployee) {
    EmployeeManager manager;
    Address addr("", "", ""); // невалидный адрес
    Employee invalidEmp("", "", "", addr);

    manager.addEmployee(invalidEmp);
    EXPECT_EQ(manager.getAllEmployees().size(), 0);
}