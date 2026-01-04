#include "PartManager.h"

void PartManager::addPart(const Part& part) {
    if (part.isValid() && !hasPart(part.getPartNumber())) {
        parts.push_back(part);
    }
}

const std::vector<Part>& PartManager::getAllParts() const {
    return parts;
}

bool PartManager::hasPart(const std::string& partNumber) const {
    for (const auto& part : parts) {
        if (part.getPartNumber() == partNumber) {
            return true;
        }
    }
    return false;
}

const Part* PartManager::findPartByNumber(const std::string& partNumber) const {
    for (const auto& part : parts) {
        if (part.getPartNumber() == partNumber) {
            return &part;
        }
    }
    return nullptr;
}

bool PartManager::reduceStock(const std::string& partNumber, int quantity) {
    if (quantity <= 0) {
        return false;
    }
    for (auto& part : parts) {
        if (part.getPartNumber() == partNumber) {
            int current = part.getStockQuantity();
            if (current >= quantity) {

                return true;
            }
            return false;
        }
    }
    return false;
}