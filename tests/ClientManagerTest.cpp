#include <gtest/gtest.h>
#include "managers/ClientManager/ClientManager.h"
#include "models/Address/Address.h"

TEST(ClientManagerTest, AddValidClient) {
    ClientManager manager;
    Address addr("Moscow", "Tverskaya", "10");
    Client client("Ivan Petrov", "+79991234567", "ivan@test.ru", addr);

    manager.addClient(client);
    EXPECT_EQ(manager.getAllClients().size(), 1);
    EXPECT_TRUE(manager.hasClient("Ivan Petrov"));
}

TEST(ClientManagerTest, IgnoreDuplicateClient) {
    ClientManager manager;
    Address addr("SPb", "Nevsky", "5");
    Client client("Anna", "+79876543210", "anna@test.ru", addr);

    manager.addClient(client);
    manager.addClient(client); // дубликат
    EXPECT_EQ(manager.getAllClients().size(), 1);
}

TEST(ClientManagerTest, FindExistingClient) {
    ClientManager manager;
    Address addr("Kazan", "Bauman", "15");
    Client client("Sergey", "+79001234567", "s@test.ru", addr);
    manager.addClient(client);

    const Client* found = manager.findClientByName("Sergey");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getPhone(), "+79001234567");
}

TEST(ClientManagerTest, FindNonExistingClient) {
    ClientManager manager;
    const Client* found = manager.findClientByName("Unknown");
    EXPECT_EQ(found, nullptr);
}

TEST(ClientManagerTest, IgnoreInvalidClient) {
    ClientManager manager;
    Address addr("", "", ""); // невалидный адрес
    Client invalidClient("", "", "", addr);

    manager.addClient(invalidClient);
    EXPECT_EQ(manager.getAllClients().size(), 0);
}