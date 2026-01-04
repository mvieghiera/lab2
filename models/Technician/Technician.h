#ifndef AUTOREPAIRSHOP_TECHNICIAN_H
#define AUTOREPAIRSHOP_TECHNICIAN_H

#include "../Employee/Employee.h"

class Technician : public Employee {
private:
    std::string certification;

public:
    Technician(const std::string& name,
               const std::string& position,
               const std::string& phone,
               const Address& address,
               const std::string& certification);

    const std::string& getCertification() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_TECHNICIAN_H