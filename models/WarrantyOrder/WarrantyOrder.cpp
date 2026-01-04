#include "WarrantyOrder.h"

WarrantyOrder::WarrantyOrder(const std::string& orderId,
                             const Client& client,
                             const Car& car,
                             const Mechanic& mechanic,
                             double totalAmount,
                             const std::string& warrantyNumber)
    : Order(orderId, client, car, mechanic, totalAmount), warrantyNumber(warrantyNumber) {}

const std::string& WarrantyOrder::getWarrantyNumber() const {
    return warrantyNumber;
}

bool WarrantyOrder::isValid() const {
    return Order::isValid() && !warrantyNumber.empty();
}