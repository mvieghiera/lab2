#include "DuplicateOrderException.h"

DuplicateOrderException::DuplicateOrderException(const std::string& orderId)
    : message("DuplicateOrderException: Order with ID '" + orderId + "' already exists") {}

const char* DuplicateOrderException::what() const noexcept {
    return message.c_str();
}