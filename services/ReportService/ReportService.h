#ifndef AUTOREPAIRSHOP_REPORTSERVICE_H
#define AUTOREPAIRSHOP_REPORTSERVICE_H

#include <string>
#include <vector>

class Order;
class Payment;
class Service;

class ReportService {
public:

    void generateOrderReport(const std::string& orderId,
                             const std::string& clientName,
                             const std::string& carInfo,
                             double totalAmount) const;


    void generateFinancialReport(const std::vector<double>& payments) const;


    void generateServiceReport(const std::vector<std::string>& serviceNames) const;
};

#endif // AUTOREPAIRSHOP_REPORTSERVICE_H