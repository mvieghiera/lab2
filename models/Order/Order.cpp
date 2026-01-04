#include "Order.h"

Order::Order(const std::string& orderId,
             const Client& client,
             const Car& car,
             const Mechanic& mechanic,
             double totalAmount)
    : orderId(orderId),
      client(client),
      car(car),
      mechanic(mechanic),
      invoice(orderId, totalAmount) {}

const std::string& Order::getOrderId() const {
    return orderId;
}

const Client& Order::getClient() const {
    return client;
}

const Car& Order::getCar() const {
    return car;
}

const Mechanic& Order::getMechanic() const {
    return mechanic;
}

const Invoice& Order::getInvoice() const {
    return invoice;
}

const std::vector<std::string>& Order::getServices() const {
    return serviceDescriptions;
}

void Order::addService(const std::string& description) {
    if (!description.empty()) {
        serviceDescriptions.push_back(description);
    }
}

bool Order::isValid() const {
    return !orderId.empty() &&
           client.isValid() &&
           car.isValid() &&
           mechanic.isValid() &&
           invoice.isValid() &&
           !serviceDescriptions.empty();
}