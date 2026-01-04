#ifndef AUTOREPAIRSHOP_DURABLEPART_H
#define AUTOREPAIRSHOP_DURABLEPART_H

#include "../Part/Part.h"

class DurablePart : public Part {
private:
    int warrantyMonths;

public:
    DurablePart(const std::string& partNumber,
                const std::string& name,
                double price,
                int stockQuantity,
                int warrantyMonths);

    int getWarrantyMonths() const;
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_DURABLEPART_H