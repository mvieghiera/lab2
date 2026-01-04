#include "Technician.h"
#include "services/ValidationService/ValidationService.h"

Technician::Technician(const std::string& name,
                       const std::string& position,
                       const std::string& phone,
                       const Address& address,
                       const std::string& certification)
    : Employee(name, position, phone, address), certification(certification) {}

const std::string& Technician::getCertification() const {
    return certification;
}

bool Technician::isValid() const {
    return Employee::isValid() &&
           ValidationService::isValidName(certification);
}