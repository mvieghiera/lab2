#ifndef AUTOREPAIRSHOP_INVALIDORDEREXCEPTION_H
#define AUTOREPAIRSHOP_INVALIDORDEREXCEPTION_H

#include <exception>
#include <string>


class InvalidOrderException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidOrderException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_INVALIDORDEREXCEPTION_H