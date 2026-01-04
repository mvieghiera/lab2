#ifndef AUTOREPAIRSHOP_EMPLOYEEMANAGER_H
#define AUTOREPAIRSHOP_EMPLOYEEMANAGER_H

#include <vector>
#include <string>
#include "../../models/Employee/Employee.h"


class EmployeeManager {
private:
    std::vector<Employee> employees;

public:
    void addEmployee(const Employee& employee);
    const std::vector<Employee>& getAllEmployees() const;
    bool hasEmployee(const std::string& employeeName) const;
    const Employee* findEmployeeByName(const std::string& name) const;
};

#endif // AUTOREPAIRSHOP_EMPLOYEEMANAGER_H