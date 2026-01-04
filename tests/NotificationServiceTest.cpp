#include <gtest/gtest.h>
#include "services/NotificationService/NotificationService.h"
#include <sstream>
#include <iostream>

TEST(NotificationServiceTest, NotifyClient_DoesNotCrash) {
    NotificationService service;
    ASSERT_NO_THROW({
        service.notifyClient("Ivan", "Ваш заказ создан!");
    });
}

TEST(NotificationServiceTest, NotifyEmployee_DoesNotCrash) {
    NotificationService service;
    ASSERT_NO_THROW({
        service.notifyEmployee("Sergey", "Назначен новый заказ.");
    });
}