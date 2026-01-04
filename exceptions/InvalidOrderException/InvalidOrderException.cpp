#include "InvalidOrderException.h"

InvalidOrderException::InvalidOrderException(const std::string& msg)
    : message("InvalidOrderException: " + msg) {}

const char* InvalidOrderException::what() const noexcept {
    return message.c_str();
}