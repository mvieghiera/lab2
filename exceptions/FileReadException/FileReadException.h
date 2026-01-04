#ifndef AUTOREPAIRSHOP_FILEREAD_EXCEPTION_H
#define AUTOREPAIRSHOP_FILEREAD_EXCEPTION_H

#include <exception>
#include <string>


class FileReadException : public std::exception {
private:
    std::string message;

public:
    explicit FileReadException(const std::string& filename);
    const char* what() const noexcept override;
};

#endif // AUTOREPAIRSHOP_FILEREAD_EXCEPTION_H