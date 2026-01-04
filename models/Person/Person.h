#ifndef AUTOREPAIRSHOP_PERSON_H
#define AUTOREPAIRSHOP_PERSON_H

#include <string>
#include "../Address/Address.h"

class Person {
protected:
    std::string name;
    std::string phone;
    Address address;

public:
    Person(const std::string& name,
           const std::string& phone,
           const Address& address);

    const std::string& getName() const;
    const std::string& getPhone() const;
    const Address& getAddress() const;

    virtual bool isValid() const;
    virtual ~Person() = default;
};

#endif // AUTOREPAIRSHOP_PERSON_H