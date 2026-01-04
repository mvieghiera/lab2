#ifndef AUTOREPAIRSHOP_PASSENGERCAR_H
#define AUTOREPAIRSHOP_PASSENGERCAR_H

#include "../Car/Car.h"

class PassengerCar : public Car {
private:
    int seats;

public:
    PassengerCar(const std::string& brand,
                 const std::string& model,
                 int year,
                 const std::string& licensePlate,
                 int seats);

    int getSeats() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_PASSENGERCAR_H