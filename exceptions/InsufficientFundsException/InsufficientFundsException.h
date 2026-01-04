#ifndef AUTOREPAIRSHOP_INSUFFICIENTFUNDSEXCEPTION_H
#define AUTOREPAIRSHOP_INSUFFICIENTFUNDSEXCEPTION_H

#include <exception>
#include <string>


class InsufficientFundsException : public std::exception {
private:
    std::string message;

public:
    explicit InsufficientFundsException(double requiredAmount, double availableAmount);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_INSUFFICIENTFUNDSEXCEPTION_H