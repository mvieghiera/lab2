#ifndef AUTOREPAIRSHOP_NOTIFICATIONSERVICE_H
#define AUTOREPAIRSHOP_NOTIFICATIONSERVICE_H

#include <string>


class NotificationService {
public:

    void notifyClient(const std::string& clientName, const std::string& message) const;

    void notifyEmployee(const std::string& employeeName, const std::string& message) const;
};

#endif // AUTOREPAIRSHOP_NOTIFICATIONSERVICE_H