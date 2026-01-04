#include "ValidationService.h"
#include <cctype>
#include <algorithm>

bool ValidationService::isValidName(const std::string& name) {
    if (name.empty()) return false;
    return std::find_if(name.begin(), name.end(), ::isdigit) == name.end();
}

bool ValidationService::isValidPhoneFormat(const std::string& phone) {
    if (phone.empty()) return false;
    for (char c : phone) {
        if (!std::isdigit(c) && c != '+' && c != '-' && c != '(' && c != ')' && c != ' ') {
            return false;
        }
    }
    return true;
}

bool ValidationService::isValidEmailFormat(const std::string& email) {
    if (email.empty()) return false;
    size_t atPos = email.find('@');
    if (atPos == std::string::npos || atPos == 0 || atPos == email.size() - 1) {
        return false;
    }
    size_t dotPos = email.rfind('.');
    if (dotPos == std::string::npos || dotPos <= atPos + 1 || dotPos == email.size() - 1) {
        return false;
    }
    return true;
}

bool ValidationService::isPositive(double value) {
    return value > 0.0;
}