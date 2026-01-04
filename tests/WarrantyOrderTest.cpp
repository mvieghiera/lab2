#include <gtest/gtest.h>
#include "models/WarrantyOrder/WarrantyOrder.h"
#include "models/Address/Address.h"



TEST(WarrantyOrderTest, InvalidWarrantyNumber) {
    Address clientAddr("Kazan", "Bauman", "10");
    Client client("Anna", "+7777", "a@test.ru", clientAddr);
    Car car("Toyota", "Corolla", 2021, "B002AB");
    Mechanic mechanic("Petr", "+7666", clientAddr, "Electronics");

    WarrantyOrder order("ORD-W-002", client, car, mechanic, 0.0, "");

    EXPECT_FALSE(order.isValid());
}