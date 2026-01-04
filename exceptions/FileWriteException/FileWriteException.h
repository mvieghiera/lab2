#ifndef AUTOREPAIRSHOP_FILEWRITEEXCEPTION_H
#define AUTOREPAIRSHOP_FILEWRITEEXCEPTION_H

#include <exception>
#include <string>


class FileWriteException : public std::exception {
private:
    std::string message;

public:
    explicit FileWriteException(const std::string& filename);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_FILEWRITEEXCEPTION_H