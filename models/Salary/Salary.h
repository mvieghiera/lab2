#ifndef AUTOREPAIRSHOP_SALARY_H
#define AUTOREPAIRSHOP_SALARY_H

class Salary {
private:
    double baseAmount;
    double bonus;
    double total;

public:

    Salary(double baseAmount, double bonus);

    double getBaseAmount() const;
    double getBonus() const;
    double getTotal() const;

    bool isValid() const;
};

#endif // AUTOREPAIRSHOP_SALARY_H