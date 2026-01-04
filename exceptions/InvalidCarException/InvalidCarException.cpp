#include "InvalidCarException.h"

InvalidCarException::InvalidCarException(const std::string& msg) : message(msg) {}

const char* InvalidCarException::what() const noexcept {
    return message.c_str();
}