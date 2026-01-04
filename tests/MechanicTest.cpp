#include <gtest/gtest.h>
#include "models/Mechanic/Mechanic.h"
#include "models/Address/Address.h"

TEST(MechanicTest, ValidMechanic) {
    Address addr("Ufa", "Lenina", "5");
    Mechanic mech("Dmitry", "+7 987 654-32-10", addr, "Transmission");
    EXPECT_TRUE(mech.isValid());
    EXPECT_EQ(mech.getSpecialization(), "Transmission");
    EXPECT_EQ(mech.getPosition(), "Mechanic");
}

TEST(MechanicTest, InvalidMechanic_EmptySpecialization) {
    Address addr("Samara", "Gagarina", "2");
    Mechanic mech("Ivan", "+79991112233", addr, "");
    EXPECT_FALSE(mech.isValid());
}

TEST(MechanicTest, PolymorphismTest) {
    Address addr("Rostov", "Mikhaila", "15");
    Mechanic mech("Sergey", "+79001234567", addr, "Electronics");

    Employee* emp = &mech;
    EXPECT_TRUE(emp->isValid()); // вызовется Mechanic::isValid()
}