#ifndef AUTOREPAIRSHOP_CLIENT_H
#define AUTOREPAIRSHOP_CLIENT_H

#include <string>
#include "../Person/Person.h"  // ← наследуем от Person

class Client : public Person {
private:
    std::string email;

public:
    Client(const std::string& name,
           const std::string& phone,
           const std::string& email,
           const Address& address);

    const std::string& getEmail() const;

    void setPhone(const std::string& newPhone);
    void setEmail(const std::string& newEmail);

    bool isValid() const override;
};

#endif // AUTOREPAIRSHOP_CLIENT_H