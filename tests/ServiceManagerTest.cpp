#include <gtest/gtest.h>
#include "managers/ServiceManager/ServiceManager.h"

TEST(ServiceManagerTest, AddValidService) {
    ServiceManager manager;
    Service oilChange("Замена масла", 1500.0);

    manager.addService(oilChange);
    EXPECT_EQ(manager.getAllServices().size(), 1);
    EXPECT_TRUE(manager.hasService("Замена масла"));
}

TEST(ServiceManagerTest, IgnoreDuplicateService) {
    ServiceManager manager;
    Service diag("Диагностика", 2000.0);

    manager.addService(diag);
    manager.addService(diag); // дубликат
    EXPECT_EQ(manager.getAllServices().size(), 1);
}

TEST(ServiceManagerTest, FindExistingService) {
    ServiceManager manager;
    Service service("Шиномонтаж", 800.0);
    manager.addService(service);

    const Service* found = manager.findServiceByName("Шиномонтаж");
    ASSERT_NE(found, nullptr);
    EXPECT_DOUBLE_EQ(found->getPrice(), 800.0);
}

TEST(ServiceManagerTest, FindNonExistingService) {
    ServiceManager manager;
    const Service* found = manager.findServiceByName("Неизвестная услуга");
    EXPECT_EQ(found, nullptr);
}