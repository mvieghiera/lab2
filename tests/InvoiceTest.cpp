#include <gtest/gtest.h>
#include "models/Invoice/Invoice.h"

TEST(InvoiceTest, ValidInvoice) {
    Invoice inv("INV-001", 1500.50);
    EXPECT_TRUE(inv.isValid());
    EXPECT_EQ(inv.getInvoiceId(), "INV-001");
    EXPECT_DOUBLE_EQ(inv.getAmount(), 1500.50);
    EXPECT_EQ(inv.getStatus(), Invoice::Status::Pending);
}

TEST(InvoiceTest, MarkAsPaid) {
    Invoice inv("INV-002", 2000.0);
    inv.markAsPaid();
    EXPECT_EQ(inv.getStatus(), Invoice::Status::Paid);
}

TEST(InvoiceTest, CancelInvoice) {
    Invoice inv("INV-003", 100.0);
    inv.cancel();
    EXPECT_EQ(inv.getStatus(), Invoice::Status::Cancelled);
}

TEST(InvoiceTest, CannotPayCancelledInvoice) {
    Invoice inv("INV-004", 500.0);
    inv.cancel();
    inv.markAsPaid(); // должно игнорироваться
    EXPECT_EQ(inv.getStatus(), Invoice::Status::Cancelled);
}

TEST(InvoiceTest, InvalidInvoice_ZeroAmount) {
    Invoice inv("INV-005", 0.0);
    EXPECT_FALSE(inv.isValid());
}