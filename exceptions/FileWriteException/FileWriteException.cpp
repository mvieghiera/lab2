#include "FileWriteException.h"

FileWriteException::FileWriteException(const std::string& filename)
    : message("FileWriteException: Unable to write to file '" + filename + "'") {}

const char* FileWriteException::what() const noexcept {
    return message.c_str();
}