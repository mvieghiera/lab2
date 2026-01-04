#include "PassengerCar.h"

PassengerCar::PassengerCar(const std::string& brand,
                           const std::string& model,
                           int year,
                           const std::string& licensePlate,
                           int seats)
    : Car(brand, model, year, licensePlate), seats(seats) {}

int PassengerCar::getSeats() const {
    return seats;
}

bool PassengerCar::isValid() const {
    return Car::isValid() && seats >= 2 && seats <= 8;
}