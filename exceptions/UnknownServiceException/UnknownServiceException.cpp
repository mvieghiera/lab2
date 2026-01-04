#include "UnknownServiceException.h"

UnknownServiceException::UnknownServiceException(const std::string& serviceName)
    : message("UnknownServiceException: Service '" + serviceName + "' not found in catalog") {}

const char* UnknownServiceException::what() const noexcept {
    return message.c_str();
}