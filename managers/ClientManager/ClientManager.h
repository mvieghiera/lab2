#ifndef AUTOREPAIRSHOP_CLIENTMANAGER_H
#define AUTOREPAIRSHOP_CLIENTMANAGER_H

#include <vector>
#include <string>
#include "../../models/Client/Client.h"


class ClientManager {
private:
    std::vector<Client> clients;

public:
    void addClient(const Client& client);
    const std::vector<Client>& getAllClients() const;
    bool hasClient(const std::string& clientName) const;
    const Client* findClientByName(const std::string& name) const;
};

#endif // AUTOREPAIRSHOP_CLIENTMANAGER_H