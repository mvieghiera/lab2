#ifndef AUTOREPAIRSHOP_INVALIDCLIENTEXCEPTION_H
#define AUTOREPAIRSHOP_INVALIDCLIENTEXCEPTION_H

#include <exception>
#include <string>

class InvalidClientException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidClientException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_INVALIDCLIENTEXCEPTION_H