#include "Address.h"

Address::Address(const std::string& city, const std::string& street, const std::string& houseNumber)
    : city(city), street(street), houseNumber(houseNumber) {}

const std::string& Address::getCity() const {
    return city;
}

const std::string& Address::getStreet() const {
    return street;
}

const std::string& Address::getHouseNumber() const {
    return houseNumber;
}

bool Address::isValid() const {
    return !city.empty() && !street.empty() && !houseNumber.empty();
}
