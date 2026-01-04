#include "Car.h"
#include "config/Constants.h"

Car::Car(const std::string& brand, const std::string& model, int year, const std::string& licensePlate)
    : brand(brand), model(model), year(year), licensePlate(licensePlate) {}

const std::string& Car::getBrand() const { return brand; }
const std::string& Car::getModel() const { return model; }
int Car::getYear() const { return year; }
const std::string& Car::getLicensePlate() const { return licensePlate; }

bool Car::isValid() const {
    return !brand.empty() && !model.empty() && year >= MIN_CAR_YEAR && !licensePlate.empty();
}