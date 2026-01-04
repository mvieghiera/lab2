#ifndef AUTOREPAIRSHOP_PART_H
#define AUTOREPAIRSHOP_PART_H

#include <string>

class Part {
private:
    std::string partNumber;   // Артикул (уникальный, например: "BRK-2026-001")
    std::string name;         // Название (например: "Тормозные колодки")
    double price;             // Цена за единицу
    int stockQuantity;        // Количество на складе

public:
    Part(const std::string& partNumber,
         const std::string& name,
         double price,
         int stockQuantity);

    const std::string& getPartNumber() const;
    const std::string& getName() const;
    double getPrice() const;
    int getStockQuantity() const;
    void setStockQuantity(int quantity);
    void reduceStock(int amount);
    virtual bool isValid() const;
};

#endif // AUTOREPAIRSHOP_PART_H