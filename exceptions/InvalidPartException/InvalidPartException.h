#ifndef AUTOREPAIRSHOP_INVALIDPARTEXCEPTION_H
#define AUTOREPAIRSHOP_INVALIDPARTEXCEPTION_H

#include <exception>
#include <string>


class InvalidPartException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidPartException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_INVALIDPARTEXCEPTION_H