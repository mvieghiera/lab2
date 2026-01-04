#include "DatabaseConnectionException.h"

DatabaseConnectionException::DatabaseConnectionException(const std::string& details)
    : message("DatabaseConnectionException: Failed to connect to database. Details: " + details) {}

const char* DatabaseConnectionException::what() const noexcept {
    return message.c_str();
}