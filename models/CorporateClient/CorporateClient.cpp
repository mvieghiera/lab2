#include "CorporateClient.h"
#include "services/ValidationService/ValidationService.h"

CorporateClient::CorporateClient(const std::string& name,
                                 const std::string& phone,
                                 const std::string& email,
                                 const Address& address,
                                 const std::string& companyName,
                                 const std::string& taxId)
    : Client(name, phone, email, address), companyName(companyName), taxId(taxId) {}

const std::string& CorporateClient::getCompanyName() const {
    return companyName;
}

const std::string& CorporateClient::getTaxId() const {
    return taxId;
}
void CorporateClient::setCompanyName(const std::string& name) {
    if (!name.empty()) {
        companyName = name;
    }
}

void CorporateClient::setTaxId(const std::string& id) {
    if (!id.empty()) {
        taxId = id;
    }
}
bool CorporateClient::isValid() const {
    return Client::isValid() &&
           !companyName.empty() &&
           ValidationService::isValidName(taxId);
}