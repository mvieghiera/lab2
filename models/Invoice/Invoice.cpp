#include "Invoice.h"
#include "config/Constants.h"

Invoice::Invoice(const std::string& invoiceId, double amount)
    : invoiceId(invoiceId), amount(amount), status(Status::Pending) {}

const std::string& Invoice::getInvoiceId() const {
    return invoiceId;
}

double Invoice::getAmount() const {
    return amount;
}

Invoice::Status Invoice::getStatus() const {
    return status;
}

void Invoice::markAsPaid() {
    if (status != Status::Cancelled) {
        status = Status::Paid;
    }
}

void Invoice::cancel() {
    status = Status::Cancelled;
}

bool Invoice::isValid() const {
    return !invoiceId.empty() && amount >= MIN_INVOICE_AMOUNT;
}