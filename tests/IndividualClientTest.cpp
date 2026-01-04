#include <gtest/gtest.h>
#include "models/IndividualClient/IndividualClient.h"
#include "models/Address/Address.h"


TEST(IndividualClientTest, InvalidPassportNumber) {
    Address addr("SPb", "Nevsky", "5");
    IndividualClient client("Anna", "+7888", "a@test.ru", addr, "");

    EXPECT_FALSE(client.isValid());
}