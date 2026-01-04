#include "InvalidClientException.h"

InvalidClientException::InvalidClientException(const std::string& msg)
    : message("InvalidClientException: " + msg) {}

const char* InvalidClientException::what() const noexcept {
    return message.c_str();
}