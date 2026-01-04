#include "Part.h"
#include "config/Constants.h"

Part::Part(const std::string& partNumber,
           const std::string& name,
           double price,
           int stockQuantity)
    : partNumber(partNumber), name(name), price(price), stockQuantity(stockQuantity) {}

const std::string& Part::getPartNumber() const {
    return partNumber;
}

const std::string& Part::getName() const {
    return name;
}

double Part::getPrice() const {
    return price;
}

int Part::getStockQuantity() const {
    return stockQuantity;
}
void Part::setStockQuantity(int quantity) {
    if (quantity >= 0) {
        stockQuantity = quantity;
    }
}

void Part::reduceStock(int amount) {
    if (amount > 0 && stockQuantity >= amount) {
        stockQuantity -= amount;
    }
    // Или бросать исключение при недостатке
}
bool Part::isValid() const {
    return !partNumber.empty() &&
           !name.empty() &&
           price >= MIN_PART_PRICE &&
           stockQuantity >= MIN_STOCK_QUANTITY;
}