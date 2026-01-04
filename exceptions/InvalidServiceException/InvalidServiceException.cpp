#include "InvalidServiceException.h"

InvalidServiceException::InvalidServiceException(const std::string& msg)
    : message("InvalidServiceException: " + msg) {}

const char* InvalidServiceException::what() const noexcept {
    return message.c_str();
}