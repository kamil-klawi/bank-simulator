//
// Created by kamil on 3/29/25.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"

class Account : public User {
public:
    Account(
        std::string& idNumber,
        std::string& firstName,
        std::string& lastName,
        std::string& email,
        int day,
        int month,
        int year
        ) : User(idNumber, firstName, lastName, email, day, month, year) {}

    double getBalance() const;
    bool isActive() const;

    void createAccount(std::string& login, std::string& passwd, std::string& confirmPasswd, double balance);
    static void editAccount(Account& account);
    void deleteAccount();
    void activateAccount();
    void setLogin(std::string& login);
    void setPasswd(std::string& passwd);
private:
    std::string login;
    std::string passwd;
    std::string confirmPasswd;
    double balance;
    bool active;
};

#endif //ACCOUNT_H
