#ifndef AUTOREPAIRSHOP_PAYMENTMANAGER_H
#define AUTOREPAIRSHOP_PAYMENTMANAGER_H

#include <vector>
#include <string>
#include "../../models/Payment/Payment.h"


class PaymentManager {
private:
    std::vector<Payment> payments;

public:
    void addPayment(const Payment& payment);
    const std::vector<Payment>& getAllPayments() const;
    bool hasPayment(const std::string& paymentId) const;
    const Payment* findPaymentById(const std::string& paymentId) const;
    bool processPayment(const std::string& paymentId);
};

#endif // AUTOREPAIRSHOP_PAYMENTMANAGER_H