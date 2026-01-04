#ifndef AUTOREPAIRSHOP_MANAGER_H
#define AUTOREPAIRSHOP_MANAGER_H

#include "../Employee/Employee.h"
#include <string>

class Manager : public Employee {
private:
    std::string department;

public:
    Manager(const std::string& name,
            const std::string& phone,
            const Address& address,
            const std::string& department);

    const std::string& getDepartment() const;
    void setDepartment(const std::string& department);
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_MANAGER_H