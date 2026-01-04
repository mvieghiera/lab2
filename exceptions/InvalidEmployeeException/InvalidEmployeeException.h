#ifndef AUTOREPAIRSHOP_INVALIDEMPLOYEEEXCEPTION_H
#define AUTOREPAIRSHOP_INVALIDEMPLOYEEEXCEPTION_H

#include <exception>
#include <string>


class InvalidEmployeeException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidEmployeeException(const std::string& msg);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_INVALIDEMPLOYEEEXCEPTION_H