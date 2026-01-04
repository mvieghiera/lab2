// tests/CarTest.cpp
#include <gtest/gtest.h>
#include "models/Car/Car.h"

TEST(CarTest, ValidCar) {
    Car car("Toyota", "Camry", 2020, "A123BC");
    EXPECT_TRUE(car.isValid());
    EXPECT_EQ(car.getBrand(), "Toyota");
}

TEST(CarTest, InvalidYear) {
    Car car("Ford", "Focus", 1800, "X999XX");
    EXPECT_FALSE(car.isValid());
}