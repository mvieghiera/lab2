#include <gtest/gtest.h>
#include "managers/OrderManager/OrderManager.h"
#include "models/Address/Address.h"
#include "models/Client/Client.h"
#include "models/Car/Car.h"
#include "models/Mechanic/Mechanic.h"

TEST(OrderManagerTest, CreateValidOrder) {
    OrderManager manager;

    Address clientAddr("Moscow", "Tverskaya", "10");
    Client client("Ivan Petrov", "+79991234567", "ivan@test.ru", clientAddr);

    Car car("Toyota", "Camry", 2020, "A123BC");

    Address mechAddr("SPb", "Nevsky", "5");
    Mechanic mechanic("Sergey", "+79876543210", mechAddr, "Engine");

    bool result = manager.createOrder("ORD-001", client, car, mechanic, 15000.0);
    EXPECT_TRUE(result);
    EXPECT_EQ(manager.getAllOrders().size(), 1);

    const Order* order = manager.findOrderById("ORD-001");
    ASSERT_NE(order, nullptr);
    EXPECT_EQ(order->getClient().getName(), "Ivan Petrov");
    EXPECT_EQ(order->getCar().getBrand(), "Toyota");
    EXPECT_EQ(order->getMechanic().getSpecialization(), "Engine");
}

TEST(OrderManagerTest, RejectDuplicateOrderId) {
    OrderManager manager;

    Address addr1("Msk", "Lenina", "1");
    Client client("Anna", "+7999", "a@test.ru", addr1);
    Car car("Lada", "Vesta", 2022, "X001XX");
    Address addr2("Kazan", "Bauman", "10");
    Mechanic mechanic("Petr", "+7888", addr2, "Electronics");

    bool first = manager.createOrder("ORD-100", client, car, mechanic, 5000.0);
    bool second = manager.createOrder("ORD-100", client, car, mechanic, 5000.0);

    EXPECT_TRUE(first);
    EXPECT_FALSE(second);
    EXPECT_EQ(manager.getAllOrders().size(), 1);
}

TEST(OrderManagerTest, RejectInvalidClient) {
    OrderManager manager;

    Address invalidAddr("", "", "");
    Client invalidClient("", "", "", invalidAddr);
    Car car("Ford", "Focus", 2021, "B002AB");
    Address mechAddr("Rostov", "Pushkina", "20");
    Mechanic mechanic("Dmitry", "+7777", mechAddr, "Transmission");

    bool result = manager.createOrder("ORD-002", invalidClient, car, mechanic, 10000.0);
    EXPECT_FALSE(result);
    EXPECT_TRUE(manager.getAllOrders().empty());
}

TEST(OrderManagerTest, RejectInvalidCar) {
    OrderManager manager;

    Address clientAddr("Omsk", "Gorkogo", "3");
    Client client("Elena", "+7666", "e@test.ru", clientAddr);
    Car invalidCar("", "", 1800, ""); // пустые бренд/модель, старый год
    Address mechAddr("Vladivostok", "Admirala", "50");
    Mechanic mechanic("Alexey", "+7555", mechAddr, "General");

    bool result = manager.createOrder("ORD-003", client, invalidCar, mechanic, 8000.0);
    EXPECT_FALSE(result);
    EXPECT_TRUE(manager.getAllOrders().empty());
}

TEST(OrderManagerTest, RejectInvalidMechanic) {
    OrderManager manager;

    Address clientAddr("Novosibirsk", "Krasny", "15");
    Client client("Igor", "+7444", "i@test.ru", clientAddr);
    Car car("Honda", "Civic", 2023, "C003CD");
    Address invalidMechAddr("", "", "");
    Mechanic invalidMechanic("", "", invalidMechAddr, ""); // пустое имя и специализация

    bool result = manager.createOrder("ORD-004", client, car, invalidMechanic, 12000.0);
    EXPECT_FALSE(result);
    EXPECT_TRUE(manager.getAllOrders().empty());
}

TEST(OrderManagerTest, FindOrderById) {
    OrderManager manager;

    Address addr("Ufa", "Zakharova", "7");
    Client client("Natalia", "+7333", "n@test.ru", addr);
    Car car("Kia", "Rio", 2020, "D004DE");
    Mechanic mechanic("Viktor", "+7222", addr, "Brakes");

    manager.createOrder("ORD-FIND", client, car, mechanic, 9000.0);

    const Order* found = manager.findOrderById("ORD-FIND");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getOrderId(), "ORD-FIND");

    const Order* notFound = manager.findOrderById("NON-EXISTENT");
    EXPECT_EQ(notFound, nullptr);
}

TEST(OrderManagerTest, GetAllOrders) {
    OrderManager manager;

    Address addr("Samara", "Chapaeva", "12");
    Client client("Mikhail", "+7111", "m@test.ru", addr);
    Car car1("BMW", "X5", 2021, "E005EF");
    Car car2("Audi", "A4", 2022, "F006FG");
    Mechanic mechanic("Andrey", "+7000", addr, "Diagnostics");

    manager.createOrder("ORD-A", client, car1, mechanic, 5000.0);
    manager.createOrder("ORD-B", client, car2, mechanic, 7000.0);

    const auto& orders = manager.getAllOrders();
    EXPECT_EQ(orders.size(), 2);
    EXPECT_EQ(orders[0].getOrderId(), "ORD-A");
    EXPECT_EQ(orders[1].getOrderId(), "ORD-B");
}