#ifndef AUTOREPAIRSHOP_CONSUMABLEPART_H
#define AUTOREPAIRSHOP_CONSUMABLEPART_H

#include "../Part/Part.h"

class ConsumablePart : public Part {
private:
    int shelfLifeDays;

public:
    ConsumablePart(const std::string& partNumber,
                   const std::string& name,
                   double price,
                   int stockQuantity,
                   int shelfLifeDays);

    int getShelfLifeDays() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_CONSUMABLEPART_H