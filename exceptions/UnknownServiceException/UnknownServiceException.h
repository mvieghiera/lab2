#ifndef AUTOREPAIRSHOP_UNKNOWNSERVICEEXCEPTION_H
#define AUTOREPAIRSHOP_UNKNOWNSERVICEEXCEPTION_H

#include <exception>
#include <string>


class UnknownServiceException : public std::exception {
private:
    std::string message;

public:
    explicit UnknownServiceException(const std::string& serviceName);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_UNKNOWNSERVICEEXCEPTION_H