#ifndef AUTOREPAIRSHOP_ORDER_H
#define AUTOREPAIRSHOP_ORDER_H

#include <string>
#include <vector>
#include "../Client/Client.h"
#include "../Car/Car.h"
#include "../Mechanic/Mechanic.h"
#include "../Invoice/Invoice.h"


class Order {
private:
    std::string orderId;
    const Client& client;
    const Car& car;
    const Mechanic& mechanic;
    Invoice invoice;
    std::vector<std::string> serviceDescriptions;

public:
    Order(const std::string& orderId,
          const Client& client,
          const Car& car,
          const Mechanic& mechanic,
          double totalAmount);

    const std::string& getOrderId() const;
    const Client& getClient() const;
    const Car& getCar() const;
    const Mechanic& getMechanic() const;
    const Invoice& getInvoice() const;
    const std::vector<std::string>& getServices() const;

    void addService(const std::string& description);
    virtual bool isValid() const;
};

#endif // AUTOREPAIRSHOP_ORDER_H