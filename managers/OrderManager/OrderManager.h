#ifndef AUTOREPAIRSHOP_ORDERMANAGER_H
#define AUTOREPAIRSHOP_ORDERMANAGER_H

#include <vector>
#include <string>
#include <memory>
#include "../../models/Order/Order.h"
#include "../../models/Client/Client.h"
#include "../../models/Car/Car.h"
#include "../../models/Employee/Employee.h" // ← принимает любой Employee (вкл. Mechanic)


class OrderManager {
private:
    std::vector<Order> orders;

public:

    bool createOrder(const std::string& orderId,
                     const Client& client,
                     const Car& car,
                     const Employee& mechanic, // ← полиморфный параметр
                     double totalAmount);

    const std::vector<Order>& getAllOrders() const;
    bool hasOrder(const std::string& orderId) const;
    const Order* findOrderById(const std::string& orderId) const;
};

#endif // AUTOREPAIRSHOP_ORDERMANAGER_H