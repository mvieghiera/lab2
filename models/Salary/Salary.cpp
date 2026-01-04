#include "Salary.h"
#include "config/Constants.h"


Salary::Salary(double baseAmount, double bonus)
    : baseAmount(baseAmount), bonus(bonus), total(baseAmount + bonus) {}

double Salary::getBaseAmount() const {
    return baseAmount;
}

double Salary::getBonus() const {
    return bonus;
}

double Salary::getTotal() const {
    return total;
}

bool Salary::isValid() const {
    return baseAmount >= MIN_SALARY && bonus >= 0.0;
}