#include <gtest/gtest.h>
#include "models/CashPayment/CashPayment.h"

TEST(CashPaymentTest, ValidCashPayment) {
    CashPayment payment("PAY-C-001", 15000.0, "REC-2026-001");

    EXPECT_TRUE(payment.isValid());
    EXPECT_EQ(payment.getReceiptNumber(), "REC-2026-001");
}

TEST(CashPaymentTest, InvalidReceiptNumber) {
    CashPayment payment("PAY-C-002", 5000.0, "");
    EXPECT_FALSE(payment.isValid());
}