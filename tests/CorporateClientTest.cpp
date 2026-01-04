#include <gtest/gtest.h>
#include "models/CorporateClient/CorporateClient.h"
#include "models/Address/Address.h"


TEST(CorporateClientTest, InvalidCompanyName) {
    Address addr("Rostov", "Pushkina", "1");
    CorporateClient client("C", "+7666", "x@test.ru", addr, "", "11111");

    EXPECT_FALSE(client.isValid());
}