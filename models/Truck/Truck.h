#ifndef AUTOREPAIRSHOP_TRUCK_H
#define AUTOREPAIRSHOP_TRUCK_H

#include "../Car/Car.h"

class Truck : public Car {
private:
    double maxLoad;

public:
    Truck(const std::string& brand,
          const std::string& model,
          int year,
          const std::string& licensePlate,
          double maxLoad);

    double getMaxLoad() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_TRUCK_H