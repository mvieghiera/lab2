#include "Person.h"
#include "services/ValidationService/ValidationService.h"

Person::Person(const std::string& name,
               const std::string& phone,
               const Address& address)
    : name(name), phone(phone), address(address) {}

const std::string& Person::getName() const {
    return name;
}

const std::string& Person::getPhone() const {
    return phone;
}

const Address& Person::getAddress() const {
    return address;
}

bool Person::isValid() const {
    return ValidationService::isValidName(name) &&
           ValidationService::isValidPhoneFormat(phone) &&
           address.isValid();
}