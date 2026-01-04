#ifndef AUTOREPAIRSHOP_PARTMANAGER_H
#define AUTOREPAIRSHOP_PARTMANAGER_H

#include <vector>
#include <string>
#include "../../models/Part/Part.h"


class PartManager {
private:
    std::vector<Part> parts;

public:
    void addPart(const Part& part);
    const std::vector<Part>& getAllParts() const;
    bool hasPart(const std::string& partNumber) const;
    const Part* findPartByNumber(const std::string& partNumber) const;
    bool reduceStock(const std::string& partNumber, int quantity);
};

#endif // AUTOREPAIRSHOP_PARTMANAGER_H