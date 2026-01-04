#ifndef AUTOREPAIRSHOP_WARRANTYORDER_H
#define AUTOREPAIRSHOP_WARRANTYORDER_H

#include "../Order/Order.h"

class WarrantyOrder : public Order {
private:
    std::string warrantyNumber;

public:
    WarrantyOrder(const std::string& orderId,
                  const Client& client,
                  const Car& car,
                  const Mechanic& mechanic,
                  double totalAmount,
                  const std::string& warrantyNumber);

    const std::string& getWarrantyNumber() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_WARRANTYORDER_H