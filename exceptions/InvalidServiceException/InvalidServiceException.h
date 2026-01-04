#ifndef AUTOREPAIRSHOP_INVALIDSERVICEEXCEPTION_H
#define AUTOREPAIRSHOP_INVALIDSERVICEEXCEPTION_H

#include <exception>
#include <string>


class InvalidServiceException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidServiceException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_INVALIDSERVICEEXCEPTION_H