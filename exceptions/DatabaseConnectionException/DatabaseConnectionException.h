#ifndef AUTOREPAIRSHOP_DATABASECONNECTIONEXCEPTION_H
#define AUTOREPAIRSHOP_DATABASECONNECTIONEXCEPTION_H

#include <exception>
#include <string>
class DatabaseConnectionException : public std::exception {
private:
    std::string message;

public:
    explicit DatabaseConnectionException(const std::string& details);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_DATABASECONNECTIONEXCEPTION_H