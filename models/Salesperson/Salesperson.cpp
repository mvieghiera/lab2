#include "Salesperson.h"

Salesperson::Salesperson(const std::string& name,
                         const std::string& position,
                         const std::string& phone,
                         const Address& address,
                         double commissionRate)
    : Employee(name, position, phone, address), commissionRate(commissionRate) {}

double Salesperson::getCommissionRate() const {
    return commissionRate;
}

bool Salesperson::isValid() const {
    return Employee::isValid() && commissionRate >= 0.0 && commissionRate <= 1.0;
}