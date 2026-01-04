#ifndef AUTOREPAIRSHOP_EMPLOYEE_H
#define AUTOREPAIRSHOP_EMPLOYEE_H

#include <string>
#include "../Person/Person.h"  // ← наследуем от Person

class Employee : public Person {
protected:
    std::string position;

public:
    Employee(const std::string& name,
             const std::string& position,
             const std::string& phone,
             const Address& address);

    const std::string& getPosition() const;

    virtual bool isValid() const override;
    void setPhone(const std::string& newPhone);
};

#endif // AUTOREPAIRSHOP_EMPLOYEE_H