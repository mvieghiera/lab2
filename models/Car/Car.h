#ifndef AUTOREPAIRSHOP_CAR_H
#define AUTOREPAIRSHOP_CAR_H

#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    std::string licensePlate;

public:
    Car(const std::string& brand, const std::string& model, int year, const std::string& licensePlate);

    const std::string& getBrand() const;
    const std::string& getModel() const;
    int getYear() const;
    const std::string& getLicensePlate() const;

   virtual bool isValid() const;
};

#endif //AUTOREPAIRSHOP_CAR_H