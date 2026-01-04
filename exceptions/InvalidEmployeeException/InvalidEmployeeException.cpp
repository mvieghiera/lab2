#include "InvalidEmployeeException.h"

InvalidEmployeeException::InvalidEmployeeException(const std::string& msg)
    : message("InvalidEmployeeException: " + msg) {}

const char* InvalidEmployeeException::what() const noexcept {
    return message.c_str();
}