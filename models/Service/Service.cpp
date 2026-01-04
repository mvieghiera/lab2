#include "Service.h"
#include "config/Constants.h"

Service::Service(const std::string& name, double price)
    : name(name), price(price) {}

const std::string& Service::getName() const {
    return name;
}

double Service::getPrice() const {
    return price;
}

bool Service::isValid() const {
    return !name.empty() && price >= MIN_SERVICE_PRICE;
}