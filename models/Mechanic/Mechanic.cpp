#include "Mechanic.h"

Mechanic::Mechanic(const std::string& name,
                   const std::string& phone,
                   const Address& address,
                   const std::string& specialization)
    : Employee(name, "Mechanic", phone, address), specialization(specialization) {}

const std::string& Mechanic::getSpecialization() const {
    return specialization;
}
void Mechanic::setSpecialization(const std::string& newSpecialization) {
    if (!newSpecialization.empty()) {
        specialization = newSpecialization;
    }
}
bool Mechanic::isValid() const {
    return Employee::isValid() && !specialization.empty();
}