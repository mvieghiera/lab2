#ifndef AUTOREPAIRSHOP_CORPORATECLIENT_H
#define AUTOREPAIRSHOP_CORPORATECLIENT_H

#include "../Client/Client.h"

class CorporateClient : public Client {
private:
    std::string taxId;
    std::string companyName;

public:
    CorporateClient(const std::string& name,
                    const std::string& phone,
                    const std::string& email,
                    const Address& address,
                    const std::string& companyName,
                    const std::string& taxId);

    const std::string& getCompanyName() const;
    const std::string& getTaxId() const;
    void setCompanyName(const std::string& companyName);
    void setTaxId(const std::string& taxId);
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_CORPORATECLIENT_H