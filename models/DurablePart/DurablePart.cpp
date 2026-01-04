#include "DurablePart.h"

DurablePart::DurablePart(const std::string& partNumber,
                         const std::string& name,
                         double price,
                         int stockQuantity,
                         int warrantyMonths)
    : Part(partNumber, name, price, stockQuantity), warrantyMonths(warrantyMonths) {}

int DurablePart::getWarrantyMonths() const {
    return warrantyMonths;
}

bool DurablePart::isValid() const {
    return Part::isValid() && warrantyMonths > 0;
}