#include "PaymentManager.h"

void PaymentManager::addPayment(const Payment& payment) {
    if (payment.isValid() && !hasPayment(payment.getPaymentId())) {
        payments.push_back(payment);
    }
}

const std::vector<Payment>& PaymentManager::getAllPayments() const {
    return payments;
}

bool PaymentManager::hasPayment(const std::string& paymentId) const {
    for (const auto& payment : payments) {
        if (payment.getPaymentId() == paymentId) {
            return true;
        }
    }
    return false;
}

const Payment* PaymentManager::findPaymentById(const std::string& paymentId) const {
    for (const auto& payment : payments) {
        if (payment.getPaymentId() == paymentId) {
            return &payment;
        }
    }
    return nullptr;
}

bool PaymentManager::processPayment(const std::string& paymentId) {
    for (auto& payment : payments) {
        if (payment.getPaymentId() == paymentId) {
            if (payment.getStatus() == Payment::Status::Pending) {
                payment.complete();
                return true;
            }
            return false; // уже обработан
        }
    }
    return false; // платёж не найден
}