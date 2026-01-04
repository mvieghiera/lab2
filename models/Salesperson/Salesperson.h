#ifndef AUTOREPAIRSHOP_SALESPERSON_H
#define AUTOREPAIRSHOP_SALESPERSON_H

#include "../Employee/Employee.h"

class Salesperson : public Employee {
private:
    double commissionRate;

public:
    Salesperson(const std::string& name,
                const std::string& position,
                const std::string& phone,
                const Address& address,
                double commissionRate);

    double getCommissionRate() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_SALESPERSON_H