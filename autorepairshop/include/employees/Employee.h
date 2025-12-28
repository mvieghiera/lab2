#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../entities/Person.h"
#include "../entities/BankAccount.h"
#include <vector>
#include <string>
#include <ctime>

class Employee : public Person {
protected:
    std::string employeeId;
    std::string position;
    double salary;
    time_t hireDate;
    std::string department;
    BankAccount salaryAccount;
    std::vector<std::string> skills;
    std::string shift;
    double hoursWorked;

public:
    Employee(const std::string& fn, const std::string& ln, const std::string& ph,
             const std::string& empId, const std::string& pos, double sal);

    void receiveSalary();
    virtual double calculateBonus() const;
    void addHoursWorked(double hours);
    void setShift(const std::string& s);
    void addSkill(const std::string& skill);
    bool hasSkill(const std::string& skill) const;

    std::string getEmployeeId() const { return employeeId; }
    std::string getPosition() const { return position; }
    double getSalary() const { return salary; }
    std::string getDepartment() const { return department; }
    double getHoursWorked() const { return hoursWorked; }
    std::string getShift() const { return shift; }
    std::vector<std::string> getSkills() const { return skills; }
    time_t getHireDate() const { return hireDate; }
    BankAccount& getSalaryAccount() { return salaryAccount; }

    void setSalary(double s) { salary = s; }
    void setDepartment(const std::string& dept) { department = dept; }
    void setPosition(const std::string& pos) { position = pos; }
};

#endif
