#include "EmployeeManager.h"

void EmployeeManager::addEmployee(const Employee& employee) {
    if (employee.isValid() && !hasEmployee(employee.getName())) {
        employees.push_back(employee);
    }
}

const std::vector<Employee>& EmployeeManager::getAllEmployees() const {
    return employees;
}

bool EmployeeManager::hasEmployee(const std::string& employeeName) const {
    for (const auto& emp : employees) {
        if (emp.getName() == employeeName) {
            return true;
        }
    }
    return false;
}

const Employee* EmployeeManager::findEmployeeByName(const std::string& name) const {
    for (const auto& emp : employees) {
        if (emp.getName() == name) {
            return &emp;
        }
    }
    return nullptr;
}