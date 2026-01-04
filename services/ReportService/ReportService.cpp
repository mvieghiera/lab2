#include "ReportService.h"
#include <iostream>
#include <iomanip>

void ReportService::generateOrderReport(const std::string& orderId,
                                        const std::string& clientName,
                                        const std::string& carInfo,
                                        double totalAmount) const {
    std::cout << "=== ОТЧЁТ ПО ЗАКАЗУ ===" << std::endl;
    std::cout << "ID заказа: " << orderId << std::endl;
    std::cout << "Клиент: " << clientName << std::endl;
    std::cout << "Автомобиль: " << carInfo << std::endl;
    std::cout << "Сумма: " << std::fixed << std::setprecision(2) << totalAmount << " руб." << std::endl;
    std::cout << "========================" << std::endl;
}

void ReportService::generateFinancialReport(const std::vector<double>& payments) const {
    double total = 0.0;
    for (double amount : payments) {
        total += amount;
    }

    std::cout << "=== ФИНАНСОВЫЙ ОТЧЁТ ===" << std::endl;
    std::cout << "Количество платежей: " << payments.size() << std::endl;
    std::cout << "Общая выручка: " << std::fixed << std::setprecision(2) << total << " руб." << std::endl;
    std::cout << "========================" << std::endl;
}

void ReportService::generateServiceReport(const std::vector<std::string>& serviceNames) const {
    std::cout << "=== ОТЧЁТ ПО УСЛУГАМ ===" << std::endl;
    std::cout << "Популярные услуги:" << std::endl;
    for (size_t i = 0; i < serviceNames.size(); ++i) {
        std::cout << (i + 1) << ". " << serviceNames[i] << std::endl;
    }
    if (serviceNames.empty()) {
        std::cout << "Нет данных" << std::endl;
    }
    std::cout << "========================" << std::endl;
}