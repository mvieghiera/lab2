// tests/OrderTest.cpp
#include <gtest/gtest.h>
#include "models/Order/Order.h"
#include "models/Client/Client.h"
#include "models/Car/Car.h"
#include "models/Mechanic/Mechanic.h"
#include "models/Address/Address.h"

TEST(OrderTest, ValidOrder) {
    Address clientAddr("Moscow", "Tverskaya", "10");
    Client client("Ivan", "+79991234567", "ivan@test.ru", clientAddr);

    Car car("Toyota", "Camry", 2020, "A123BC");

    Address mechAddr("SPb", "Nevsky", "5");
    Mechanic mechanic("Sergey", "+79876543210", mechAddr, "Engine");

    Order order("ORD-001", client, car, mechanic, 15000.0);
    order.addService("Замена масла");
    order.addService("Диагностика двигателя");

    EXPECT_TRUE(order.isValid());
    EXPECT_EQ(order.getOrderId(), "ORD-001");
    EXPECT_EQ(order.getServices().size(), 2);
    EXPECT_EQ(order.getInvoice().getAmount(), 15000.0);
}

TEST(OrderTest, InvalidOrder_NoServices) {
    // 🔸 Обязательно создайте все зависимости!
    Address clientAddr("Msk", "Lenina", "1");
    Client client("Alex", "+7999", "a@test.ru", clientAddr);

    Car car("Lada", "Granta", 2022, "B001AB");

    Address mechAddr("Kazan", "Bauman", "10");
    Mechanic mechanic("Petr", "+7888", mechAddr, "Electronics");

    // Создаём заказ БЕЗ сервисов
    Order order("ORD-002", client, car, mechanic, 5000.0);
    // НЕ вызываем order.addService()

    EXPECT_FALSE(order.isValid()); // должно быть false — сервисы обязательны
}