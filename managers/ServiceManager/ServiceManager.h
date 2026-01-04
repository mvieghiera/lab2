#ifndef AUTOREPAIRSHOP_SERVICEMANAGER_H
#define AUTOREPAIRSHOP_SERVICEMANAGER_H

#include <vector>
#include <string>
#include "../../models/Service/Service.h"


class ServiceManager {
private:
    std::vector<Service> services;

public:
    void addService(const Service& service);
    const std::vector<Service>& getAllServices() const;
    bool hasService(const std::string& serviceName) const;
    const Service* findServiceByName(const std:: string& name) const;
};

#endif // AUTOREPAIRSHOP_SERVICEMANAGER_H