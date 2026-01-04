#include "ServiceManager.h"

void ServiceManager::addService(const Service& service) {
    if (service.isValid() && !hasService(service.getName())) {
        services.push_back(service);
    }
}

const std::vector<Service>& ServiceManager::getAllServices() const {
    return services;
}

bool ServiceManager::hasService(const std::string& serviceName) const {
    for (const auto& service : services) {
        if (service.getName() == serviceName) {
            return true;
        }
    }
    return false;
}

const Service* ServiceManager::findServiceByName(const std::string& name) const {
    for (const auto& service : services) {
        if (service.getName() == name) {
            return &service;
        }
    }
    return nullptr;
}