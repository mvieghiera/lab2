#include <gtest/gtest.h>
#include "models/Payment/Payment.h"

TEST(PaymentTest, ValidPayment) {
    Payment payment("PAY-001", 15000.0);
    EXPECT_TRUE(payment.isValid());
    EXPECT_EQ(payment.getPaymentId(), "PAY-001");
    EXPECT_DOUBLE_EQ(payment.getAmount(), 15000.0);
    EXPECT_EQ(payment.getStatus(), Payment::Status::Pending);
}

TEST(PaymentTest, CompletePayment) {
    Payment payment("PAY-002", 5000.0);
    payment.complete();
    EXPECT_EQ(payment.getStatus(), Payment::Status::Completed);
}

TEST(PaymentTest, FailPayment) {
    Payment payment("PAY-003", 200.0);
    payment.fail();
    EXPECT_EQ(payment.getStatus(), Payment::Status::Failed);
}

TEST(PaymentTest, CannotCompleteCompletedPayment) {
    Payment payment("PAY-004", 1000.0);
    payment.complete();
    payment.complete(); // должно игнорироваться
    EXPECT_EQ(payment.getStatus(), Payment::Status::Completed);
}

TEST(PaymentTest, InvalidPayment_ZeroAmount) {
    Payment payment("PAY-005", 0.0);
    EXPECT_FALSE(payment.isValid());
}