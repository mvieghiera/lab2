#include "Payment.h"
#include "config/Constants.h"

Payment::Payment(const std::string& paymentId, double amount)
    : paymentId(paymentId), amount(amount), status(Status::Pending) {}

const std::string& Payment::getPaymentId() const {
    return paymentId;
}

double Payment::getAmount() const {
    return amount;
}

Payment::Status Payment::getStatus() const {
    return status;
}

void Payment::complete() {
    if (status == Status::Pending) {
        status = Status::Completed;
    }
}

void Payment::fail() {
    if (status == Status::Pending) {
        status = Status::Failed;
    }
}

bool Payment::isValid() const {
    return !paymentId.empty() && amount >= MIN_PAYMENT_AMOUNT;
}