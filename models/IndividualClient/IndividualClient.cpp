#include "IndividualClient.h"
#include "services/ValidationService/ValidationService.h"

IndividualClient::IndividualClient(const std::string& name,
                                   const std::string& phone,
                                   const std::string& email,
                                   const Address& address,
                                   const std::string& passportNumber)
    : Client(name, phone, email, address), passportNumber(passportNumber) {}

const std::string& IndividualClient::getPassportNumber() const {
    return passportNumber;
}
void IndividualClient::setPassportNumber(const std::string& newPassport) {
    if (!newPassport.empty()) {
        passportNumber = newPassport;
    }
}
bool IndividualClient::isValid() const {
    return Client::isValid() &&
           ValidationService::isValidName(passportNumber);
}