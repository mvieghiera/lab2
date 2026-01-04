#include <gtest/gtest.h>
#include "managers/PartManager/PartManager.h"

TEST(PartManagerTest, AddValidPart) {
    PartManager manager;
    Part part("FLT-2026-001", "Масляный фильтр", 450.0, 25);

    manager.addPart(part);
    EXPECT_EQ(manager.getAllParts().size(), 1);
    EXPECT_TRUE(manager.hasPart("FLT-2026-001"));
}

TEST(PartManagerTest, IgnoreDuplicatePart) {
    PartManager manager;
    Part part("BRK-001", "Колодки", 1200.0, 10);

    manager.addPart(part);
    manager.addPart(part); // дубликат
    EXPECT_EQ(manager.getAllParts().size(), 1);
}

TEST(PartManagerTest, FindExistingPart) {
    PartManager manager;
    Part part("LAMP-001", "Фара", 2000.0, 5);
    manager.addPart(part);

    const Part* found = manager.findPartByNumber("LAMP-001");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "Фара");
    EXPECT_DOUBLE_EQ(found->getPrice(), 2000.0);
}

TEST(PartManagerTest, FindNonExistingPart) {
    PartManager manager;
    const Part* found = manager.findPartByNumber("UNKNOWN");
    EXPECT_EQ(found, nullptr);
}

TEST(PartManagerTest, ReduceStock_Sufficient) {
    PartManager manager;
    Part part("OIL-001", "Масло 5W30", 800.0, 10);
    manager.addPart(part);

    bool result = manager.reduceStock("OIL-001", 3);
    EXPECT_TRUE(result);
}

TEST(PartManagerTest, ReduceStock_Insufficient) {
    PartManager manager;
    Part part("OIL-001", "Масло 5W30", 800.0, 2);
    manager.addPart(part);

    bool result = manager.reduceStock("OIL-001", 5);
    EXPECT_FALSE(result);
}

TEST(PartManagerTest, ReduceStock_NonExistingPart) {
    PartManager manager;
    bool result = manager.reduceStock("MISSING", 1);
    EXPECT_FALSE(result);
}

TEST(PartManagerTest, ReduceStock_InvalidQuantity) {
    PartManager manager;
    Part part("PART-01", "Запчасть", 1000.0, 5);
    manager.addPart(part);

    bool result = manager.reduceStock("PART-01", 0);  // ноль
    EXPECT_FALSE(result);

    result = manager.reduceStock("PART-01", -1); // отрицательное
    EXPECT_FALSE(result);
}