#ifndef AUTOREPAIRSHOP_PAYMENT_H
#define AUTOREPAIRSHOP_PAYMENT_H

#include <string>

class Payment {
public:
    enum class Status {
        Pending,
        Completed,
        Failed
    };

private:
    std::string paymentId;
    double amount;
    Status status;

public:
    Payment(const std::string& paymentId, double amount);

    const std::string& getPaymentId() const;
    double getAmount() const;
    Status getStatus() const;

    void complete();
    void fail();

    virtual bool isValid() const;
};

#endif // AUTOREPAIRSHOP_PAYMENT_H