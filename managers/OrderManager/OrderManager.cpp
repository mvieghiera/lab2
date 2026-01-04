#include "OrderManager.h"
#include <stdexcept>

bool OrderManager::createOrder(const std::string& orderId,
                               const Client& client,
                               const Car& car,
                               const Employee& mechanic,
                               double totalAmount) {
    // Проверяем валидность всех сущностей
    if (hasOrder(orderId)) {
        return false; // дубликат
    }
    if (!client.isValid() || !car.isValid() || !mechanic.isValid()) {
        return false;
    }

    // Создаём заказ и добавляем базовую услугу
    Order newOrder(orderId, client, car,
                   static_cast<const Mechanic&>(mechanic),
                   totalAmount);
    newOrder.addService("Ремонт (услуга по умолчанию)");

    if (!newOrder.isValid()) {
        return false;
    }

    orders.push_back(newOrder);
    return true;
}

const std::vector<Order>& OrderManager::getAllOrders() const {
    return orders;
}

bool OrderManager::hasOrder(const std::string& orderId) const {
    for (const auto& order : orders) {
        if (order.getOrderId() == orderId) {
            return true;
        }
    }
    return false;
}

const Order* OrderManager::findOrderById(const std::string& orderId) const {
    for (const auto& order : orders) {
        if (order.getOrderId() == orderId) {
            return &order;
        }
    }
    return nullptr;
}