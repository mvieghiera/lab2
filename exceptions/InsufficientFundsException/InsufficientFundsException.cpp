#include "InsufficientFundsException.h"
#include <string>
#include <iomanip>
#include <sstream>

InsufficientFundsException::InsufficientFundsException(double requiredAmount, double availableAmount) {
    std::ostringstream oss;
    oss << "InsufficientFundsException: Required "
        << std::fixed << std::setprecision(2) << requiredAmount
        << ", but only " << availableAmount << " available";
    message = oss.str();
}

const char* InsufficientFundsException::what() const noexcept {
    return message.c_str();
}