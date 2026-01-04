#include "ConsumablePart.h"

ConsumablePart::ConsumablePart(const std::string& partNumber,
                               const std::string& name,
                               double price,
                               int stockQuantity,
                               int shelfLifeDays)
    : Part(partNumber, name, price, stockQuantity), shelfLifeDays(shelfLifeDays) {}

int ConsumablePart::getShelfLifeDays() const {
    return shelfLifeDays;
}

bool ConsumablePart::isValid() const {
    return Part::isValid() && shelfLifeDays > 0;
}