#include "Client.h"
#include "services/ValidationService/ValidationService.h"

Client::Client(const std::string& name,
               const std::string& phone,
               const std::string& email,
               const Address& address)
    : Person(name, phone, address), email(email) {}

const std::string& Client::getEmail() const {
    return email;
}

void Client::setPhone(const std::string& newPhone) {
    if (ValidationService::isValidPhoneFormat(newPhone)) {
        phone = newPhone;
    }
    // Или: бросать исключение при невалидном номере
}

void Client::setEmail(const std::string& newEmail) {
    if (ValidationService::isValidEmailFormat(newEmail)) {
        email = newEmail;
    }
}

bool Client::isValid() const {
    return Person::isValid() &&
           ValidationService::isValidEmailFormat(email);
}