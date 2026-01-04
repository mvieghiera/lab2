#ifndef AUTOREPAIRSHOP_DUPLICATEORDEREXCEPTION_H
#define AUTOREPAIRSHOP_DUPLICATEORDEREXCEPTION_H

#include <exception>
#include <string>


class DuplicateOrderException : public std::exception {
private:
    std::string message;

public:
    explicit DuplicateOrderException(const std::string& orderId);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_DUPLICATEORDEREXCEPTION_H