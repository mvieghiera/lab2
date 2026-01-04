#include <gtest/gtest.h>
#include "../models/Client/Client.h"
#include "../models/Address/Address.h"

TEST(ClientTest, ValidClient) {
    Address addr("Moscow", "Tverskaya", "15");
    Client client("Ivan Petrov", "+7 999 123-45-67", "ivan@example.com", addr);
    EXPECT_TRUE(client.isValid());
    EXPECT_EQ(client.getName(), "Ivan Petrov");
    EXPECT_EQ(client.getAddress().getCity(), "Moscow");
}

TEST(ClientTest, InvalidClient_EmptyName) {
    Address addr("SPb", "Nevsky", "10");
    Client client("", "+79991234567", "test@test.ru", addr);
    EXPECT_FALSE(client.isValid());
}

TEST(ClientTest, InvalidEmail) {
    Address addr("Kazan", "Bauman", "5");
    Client client("Anna", "+7 800 555-35-35", "bad-email", addr);
    EXPECT_FALSE(client.isValid());
}