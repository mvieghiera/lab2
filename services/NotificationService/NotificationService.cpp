#include "NotificationService.h"
#include <iostream>

void NotificationService::notifyClient(const std::string& clientName, const std::string& message) const {
    std::cout << "[Уведомление клиенту " << clientName << "] " << message << std::endl;
}

void NotificationService::notifyEmployee(const std::string& employeeName, const std::string& message) const {
    std::cout << "[Уведомление сотруднику " << employeeName << "] " << message << std::endl;
}