#include <gtest/gtest.h>
#include "models/DurablePart/DurablePart.h"

TEST(DurablePartTest, ValidDurablePart) {
    DurablePart part("BRK-001", "Колодки", 2500.0, 20, 24);

    EXPECT_TRUE(part.isValid());
    EXPECT_EQ(part.getWarrantyMonths(), 24);
}

TEST(DurablePartTest, InvalidWarrantyMonths) {
    DurablePart part("DISK-001", "Тормозной диск", 5000.0, 10, -1);
    EXPECT_FALSE(part.isValid());
}