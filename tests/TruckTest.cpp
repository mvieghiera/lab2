#include <gtest/gtest.h>
#include "models/Truck/Truck.h"

TEST(TruckTest, ValidTruck) {
    Truck truck("KAMAZ", "6520", 2023, "C003CD", 20000.0);

    EXPECT_TRUE(truck.isValid());
    EXPECT_DOUBLE_EQ(truck.getMaxLoad(), 20000.0);
}

TEST(TruckTest, InvalidMaxLoad) {
    Truck truck("Gazel", "3302", 2020, "D004DE", -500.0);
    EXPECT_FALSE(truck.isValid());
}