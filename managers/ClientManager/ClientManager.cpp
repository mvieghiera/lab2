#include "ClientManager.h"

void ClientManager::addClient(const Client& client) {
    if (client.isValid() && !hasClient(client.getName())) {
        clients.push_back(client);
    }
}

const std::vector<Client>& ClientManager::getAllClients() const {
    return clients;
}

bool ClientManager::hasClient(const std::string& clientName) const {
    for (const auto& client : clients) {
        if (client.getName() == clientName) {
            return true;
        }
    }
    return false;
}

const Client* ClientManager::findClientByName(const std::string& name) const {
    for (const auto& client : clients) {
        if (client.getName() == name) {
            return &client;
        }
    }
    return nullptr;
}