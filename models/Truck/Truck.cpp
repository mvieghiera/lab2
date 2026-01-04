#include "Truck.h"

Truck::Truck(const std::string& brand,
             const std::string& model,
             int year,
             const std::string& licensePlate,
             double maxLoad)
    : Car(brand, model, year, licensePlate), maxLoad(maxLoad) {}

double Truck::getMaxLoad() const {
    return maxLoad;
}

bool Truck::isValid() const {
    return Car::isValid() && maxLoad > 0.0;
}