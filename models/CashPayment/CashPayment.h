#ifndef AUTOREPAIRSHOP_CASHPAYMENT_H
#define AUTOREPAIRSHOP_CASHPAYMENT_H

#include "../Payment/Payment.h"

class CashPayment : public Payment {
private:
    std::string receiptNumber;

public:
    CashPayment(const std::string& paymentId,
                double amount,
                const std::string& receiptNumber);

    const std::string& getReceiptNumber() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_CASHPAYMENT_H