//
// Created by kamil on 3/29/25.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>

#include "BankOperations.h"
#include "Transaction.h"
#include "User.h"

struct LoginAndPassword {
    std::string& login;
    std::string& password;
    std::string& confirmPassword;
    double balance;
};

class Account : public User {
public:
    Account() : User("", "", "", "", 1, 1, 1970) {}
    Account(
        const std::string& idNumber,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& email,
        int day,
        int month,
        int year
        ) : User(idNumber, firstName, lastName, email, day, month, year) {}
    std::string getLogin() const;
    std::string getPassword() const;
    double getBalance() const;
    bool isActive() const;
    static LoginAndPassword setLoginAndPassword(std::string& login, std::string& password, std::string& confirmPassword, double& balance);
    static Account setAccountDetails(std::string& idNumber, std::string& firstName, std::string& lastName, std::string& email, int& day, int& month, int& year);
    void createAccount(std::string& login, std::string& passwd, std::string& confirmPasswd, double balance);
    static Account createBankAccount(std::vector<Account> accounts, Account currentAccount);
    static void editAccount(Account& account);
    void deleteAccount();
    void activateAccount();
    void setLogin(std::string& login);
    void setPasswd(std::string& passwd);
    void performOperation(BankOperation operation, double amount);
    void deposit(double amount);
    void withdraw(double amount);
    void transfer(Account& toAccount, double amount);
    void getTransactionHistory() const;
private:
    std::string login;
    std::string passwd;
    std::string confirmPasswd;
    double balance;
    bool active;
    std::vector<Transaction> transactions_;
};

#endif //ACCOUNT_H
