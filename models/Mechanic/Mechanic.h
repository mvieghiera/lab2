#ifndef AUTOREPAIRSHOP_MECHANIC_H
#define AUTOREPAIRSHOP_MECHANIC_H

#include "../Employee/Employee.h"
#include <string>


class Mechanic : public Employee {
private:
    std::string specialization; // Например: "Двигатель", "Электрика", "Ходовая"

public:
    Mechanic(const std::string& name,
             const std::string& phone,
             const Address& address,
             const std::string& specialization);

    const std::string& getSpecialization() const;
    void setSpecialization(const std::string& specialization);
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_MECHANIC_H