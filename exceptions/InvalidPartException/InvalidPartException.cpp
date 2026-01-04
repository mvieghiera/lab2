#include "InvalidPartException.h"

InvalidPartException::InvalidPartException(const std::string& msg)
    : message("InvalidPartException: " + msg) {}

const char* InvalidPartException::what() const noexcept {
    return message.c_str();
}