#include <gtest/gtest.h>
#include "models/Part/Part.h"

TEST(PartTest, ValidPart) {
    Part part("FLT-2026-001", "Масляный фильтр", 450.0, 25);
    EXPECT_TRUE(part.isValid());
    EXPECT_EQ(part.getPartNumber(), "FLT-2026-001");
    EXPECT_EQ(part.getName(), "Масляный фильтр");
    EXPECT_DOUBLE_EQ(part.getPrice(), 450.0);
    EXPECT_EQ(part.getStockQuantity(), 25);
}

TEST(PartTest, InvalidPart_EmptyName) {
    Part part("OIL-001", "", 1200.0, 10);
    EXPECT_FALSE(part.isValid());
}

TEST(PartTest, InvalidPart_NegativePrice) {
    Part part("BRK-001", "Колодки", -100.0, 5);
    EXPECT_FALSE(part.isValid());
}

TEST(PartTest, ZeroStockAllowed) {
    Part part("LAMP-001", "Фара", 2000.0, 0);
    EXPECT_TRUE(part.isValid()); // На складе может не быть, но запчасть валидна
}