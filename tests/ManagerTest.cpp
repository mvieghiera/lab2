#include <gtest/gtest.h>
#include "models/Manager/Manager.h"
#include "models/Address/Address.h"

TEST(ManagerTest, ValidManager) {
    Address addr("Moscow", "Tverskaya", "10");
    Manager mgr("Elena Petrova", "+7 495 123-45-67", addr, "Service Department");
    EXPECT_TRUE(mgr.isValid());
    EXPECT_EQ(mgr.getName(), "Elena Petrova");
    EXPECT_EQ(mgr.getPosition(), "Manager");
    EXPECT_EQ(mgr.getDepartment(), "Service Department");
}

TEST(ManagerTest, InvalidManager_EmptyDepartment) {
    Address addr("SPb", "Nevsky", "5");
    Manager mgr("Ivan", "+79991112233", addr, "");
    EXPECT_FALSE(mgr.isValid());
}