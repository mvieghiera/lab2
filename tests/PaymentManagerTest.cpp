#include <gtest/gtest.h>
#include "managers/PaymentManager/PaymentManager.h"

TEST(PaymentManagerTest, AddValidPayment) {
    PaymentManager manager;
    Payment payment("PAY-001", 15000.0);

    manager.addPayment(payment);
    EXPECT_EQ(manager.getAllPayments().size(), 1);
    EXPECT_TRUE(manager.hasPayment("PAY-001"));
}

TEST(PaymentManagerTest, IgnoreDuplicatePayment) {
    PaymentManager manager;
    Payment payment("PAY-100", 5000.0);

    manager.addPayment(payment);
    manager.addPayment(payment); // дубликат
    EXPECT_EQ(manager.getAllPayments().size(), 1);
}

TEST(PaymentManagerTest, FindExistingPayment) {
    PaymentManager manager;
    Payment payment("PAY-FIND", 9000.0);
    manager.addPayment(payment);

    const Payment* found = manager.findPaymentById("PAY-FIND");
    ASSERT_NE(found, nullptr);
    EXPECT_DOUBLE_EQ(found->getAmount(), 9000.0);
    EXPECT_EQ(found->getStatus(), Payment::Status::Pending);
}

TEST(PaymentManagerTest, FindNonExistingPayment) {
    PaymentManager manager;
    const Payment* found = manager.findPaymentById("MISSING");
    EXPECT_EQ(found, nullptr);
}

TEST(PaymentManagerTest, ProcessValidPayment) {
    PaymentManager manager;
    Payment payment("PAY-PROC", 10000.0);
    manager.addPayment(payment);

    bool result = manager.processPayment("PAY-PROC");
    EXPECT_TRUE(result);

    const Payment* processed = manager.findPaymentById("PAY-PROC");
    ASSERT_NE(processed, nullptr);
    EXPECT_EQ(processed->getStatus(), Payment::Status::Completed);
}

TEST(PaymentManagerTest, CannotProcessCompletedPayment) {
    PaymentManager manager;
    Payment payment("PAY-DUP", 7000.0);
    manager.addPayment(payment);
    manager.processPayment("PAY-DUP"); // первый раз — успешно

    bool result = manager.processPayment("PAY-DUP"); // второй раз
    EXPECT_FALSE(result);
}

TEST(PaymentManagerTest, CannotProcessNonExistingPayment) {
    PaymentManager manager;
    bool result = manager.processPayment("UNKNOWN");
    EXPECT_FALSE(result);
}

TEST(PaymentManagerTest, IgnoreInvalidPayment) {
    PaymentManager manager;
    Payment invalidPayment("", -100.0); // невалидный

    manager.addPayment(invalidPayment);
    EXPECT_TRUE(manager.getAllPayments().empty());
}