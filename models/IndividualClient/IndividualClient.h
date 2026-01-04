#ifndef AUTOREPAIRSHOP_INDIVIDUALCLIENT_H
#define AUTOREPAIRSHOP_INDIVIDUALCLIENT_H

#include "../Client/Client.h"

class IndividualClient : public Client {
private:
    std::string passportNumber;

public:
    IndividualClient(const std::string& name,
                     const std::string& phone,
                     const std::string& email,
                     const Address& address,
                     const std::string& passportNumber);

    const std::string& getPassportNumber() const;
    void setPassportNumber(const std::string& passportNumber);
    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_INDIVIDUALCLIENT_H