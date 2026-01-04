#include <gtest/gtest.h>
#include "models/ConsumablePart/ConsumablePart.h"

TEST(ConsumablePartTest, ValidConsumablePart) {
    ConsumablePart part("OIL-001", "Масло 5W30", 800.0, 50, 730);

    EXPECT_TRUE(part.isValid());
    EXPECT_EQ(part.getShelfLifeDays(), 730);
}

TEST(ConsumablePartTest, InvalidShelfLife) {
    ConsumablePart part("FLT-001", "Фильтр", 300.0, 100, 0);
    EXPECT_FALSE(part.isValid());
}