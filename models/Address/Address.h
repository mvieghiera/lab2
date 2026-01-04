#ifndef AUTOREPAIRSHOP_ADDRESS_H
#define AUTOREPAIRSHOP_ADDRESS_H

#include <string>


class Address  {
private:
    std::string city;
    std::string street;
    std::string houseNumber;

public:
    Address(const std::string& city, const std::string& street, const std::string& houseNumber);

    const std::string& getCity() const;
    const std::string& getStreet() const;
    const std::string& getHouseNumber() const;

    bool isValid() const;
};

#endif // AUTOREPAIRSHOP_ADDRESS_H