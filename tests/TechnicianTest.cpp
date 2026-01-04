#include <gtest/gtest.h>
#include "models/Technician/Technician.h"
#include "models/Address/Address.h"

TEST(TechnicianTest, InvalidCertification) {
    Address addr("Samara", "Chapaeva", "3");
    Technician tech("Petr", "Helper", "+7444", addr, "");
    EXPECT_FALSE(tech.isValid());
}