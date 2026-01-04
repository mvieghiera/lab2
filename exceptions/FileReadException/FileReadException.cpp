#include "FileReadException.h"

FileReadException::FileReadException(const std::string& filename)
    : message("FileReadException: Unable to read file '" + filename + "'") {}

const char* FileReadException::what() const noexcept {
    return message.c_str();
}