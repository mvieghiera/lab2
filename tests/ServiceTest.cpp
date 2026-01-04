#include <gtest/gtest.h>
#include "models/Service/Service.h"

TEST(ServiceTest, ValidService) {
    Service service("Диагностика двигателя", 2500.0);
    EXPECT_TRUE(service.isValid());
    EXPECT_EQ(service.getName(), "Диагностика двигателя");
    EXPECT_DOUBLE_EQ(service.getPrice(), 2500.0);
}

TEST(ServiceTest, InvalidService_EmptyName) {
    Service service("", 1000.0);
    EXPECT_FALSE(service.isValid());
}

TEST(ServiceTest, InvalidService_ZeroPrice) {
    Service service("Шиномонтаж", 0.0);
    EXPECT_FALSE(service.isValid());
}

TEST(ServiceTest, MinimalValidPrice) {
    Service service("Осмотр", 0.01);
    EXPECT_TRUE(service.isValid());
}