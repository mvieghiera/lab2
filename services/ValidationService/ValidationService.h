#ifndef AUTOREPAIRSHOP_VALIDATIONSERVICE_H
#define AUTOREPAIRSHOP_VALIDATIONSERVICE_H

#include <string>


class ValidationService {
public:
    static bool isValidName(const std::string& name);
    static bool isValidPhoneFormat(const std::string& phone);
    static bool isValidEmailFormat(const std::string& email);
    static bool isPositive(double value);
};

#endif // AUTOREPAIRSHOP_VALIDATIONSERVICE_H