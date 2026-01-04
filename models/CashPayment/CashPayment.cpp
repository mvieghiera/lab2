#include "CashPayment.h"

CashPayment::CashPayment(const std::string& paymentId,
                         double amount,
                         const std::string& receiptNumber)
    : Payment(paymentId, amount), receiptNumber(receiptNumber) {}

const std::string& CashPayment::getReceiptNumber() const {
    return receiptNumber;
}

bool CashPayment::isValid() const {
    return Payment::isValid() && !receiptNumber.empty();
}