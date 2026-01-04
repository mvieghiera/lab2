#include <gtest/gtest.h>
#include "models/PassengerCar/PassengerCar.h"

TEST(PassengerCarTest, ValidPassengerCar) {
    PassengerCar car("Toyota", "Camry", 2020, "A123BC", 5);

    EXPECT_TRUE(car.isValid());
    EXPECT_EQ(car.getSeats(), 5);
}

TEST(PassengerCarTest, InvalidSeats_TooFew) {
    PassengerCar car("Lada", "Vesta", 2022, "X001XX", 1);
    EXPECT_FALSE(car.isValid());
}

TEST(PassengerCarTest, InvalidSeats_TooMany) {
    PassengerCar car("BMW", "X5", 2021, "B002AB", 10);
    EXPECT_FALSE(car.isValid());
}