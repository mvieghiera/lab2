#ifndef AUTOREPAIRSHOP_SERVICE_H
#define AUTOREPAIRSHOP_SERVICE_H

#include <string>

class Service {
private:
    std::string name;   // Название услуги (например: "Замена масла")
    double price;       // Стоимость услуги

public:
    Service(const std::string& name, double price);

    const std::string& getName() const;
    double getPrice() const;

    bool isValid() const;
};

#endif // AUTOREPAIRSHOP_SERVICE_H