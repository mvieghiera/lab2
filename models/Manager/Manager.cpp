#include "Manager.h"

Manager::Manager(const std::string& name,
                 const std::string& phone,
                 const Address& address,
                 const std::string& department)
    : Employee(name, "Manager", phone, address), department(department) {}

const std::string& Manager::getDepartment() const {
    return department;
}
void Manager::setDepartment(const std::string& newDepartment) {
    if (!newDepartment.empty()) {
        department = newDepartment;
    }
}
bool Manager::isValid() const {
    return Employee::isValid() && !department.empty();
}