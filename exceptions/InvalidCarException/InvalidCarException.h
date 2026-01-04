#ifndef AUTOREPAIRSHOP_INVALIDCAREXCEPTION_H
#define AUTOREPAIRSHOP_INVALIDCAREXCEPTION_H

#include <exception>
#include <string>

class InvalidCarException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidCarException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif //AUTOREPAIRSHOP_INVALIDCAREXCEPTION_H