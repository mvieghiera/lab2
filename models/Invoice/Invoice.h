#ifndef AUTOREPAIRSHOP_INVOICE_H
#define AUTOREPAIRSHOP_INVOICE_H

#include <string>

class Invoice {
public:
    enum class Status {
        Pending,
        Paid,
        Cancelled
    };

private:
    std::string invoiceId;
    double amount;
    Status status;

public:
    Invoice(const std::string& invoiceId, double amount);

    const std::string& getInvoiceId() const;
    double getAmount() const;
    Status getStatus() const;

    void markAsPaid();
    void cancel();

    bool isValid() const;
};

#endif // AUTOREPAIRSHOP_INVOICE_H