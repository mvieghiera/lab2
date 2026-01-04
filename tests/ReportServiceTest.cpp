#include <gtest/gtest.h>
#include "services/ReportService/ReportService.h"

TEST(ReportServiceTest, GenerateOrderReport_DoesNotCrash) {
    ReportService service;
    ASSERT_NO_THROW({
        service.generateOrderReport("ORD-001", "Ivan", "Toyota Camry 2020", 15000.0);
    });
}

TEST(ReportServiceTest, GenerateFinancialReport_DoesNotCrash) {
    ReportService service;
    std::vector<double> payments = {5000.0, 10000.0, 7500.0};
    ASSERT_NO_THROW({
        service.generateFinancialReport(payments);
    });
}

TEST(ReportServiceTest, GenerateServiceReport_Empty) {
    ReportService service;
    std::vector<std::string> services;
    ASSERT_NO_THROW({
        service.generateServiceReport(services);
    });
}

TEST(ReportServiceTest, GenerateServiceReport_WithServices) {
    ReportService service;
    std::vector<std::string> services = {"Замена масла", "Диагностика"};
    ASSERT_NO_THROW({
        service.generateServiceReport(services);
    });
}