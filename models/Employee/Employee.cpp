#include "Employee.h"
#include "services/ValidationService/ValidationService.h"

Employee::Employee(const std::string& name,
                   const std::string& position,
                   const std::string& phone,
                   const Address& address)
    : Person(name, phone, address), position(position) {}

const std::string& Employee::getPosition() const {
    return position;
}
void Employee::setPhone(const std::string& newPhone) {
    if (ValidationService::isValidPhoneFormat(newPhone)) {
        phone = newPhone;
    }
}
bool Employee::isValid() const {
    return Person::isValid() &&
           !position.empty();
}