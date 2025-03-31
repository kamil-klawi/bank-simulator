#include <iostream>

#include "../include/Account.h"

int main() {
    std::string idNumber = "FEJ56483";
    std::string firstName = "John";
    std::string lastName = "Doe";
    std::string email = "john.doe@example.com";
    int day = 1;
    int month = 1;
    int year = 1999;
    Account account(idNumber, firstName, lastName, email, day, month, year);
    std::string login = "john-doe";
    std::string passwd = "john123";
    std::string confirmPasswd = "john123";
    double balance = 1000.5;
    double amount = 0.1;
    account.createAccount(login, passwd, confirmPasswd, balance);
    account.activateAccount();
    // Account::editAccount(account);
    // std::cout << account.getFirstName();
    account.performOperation(DEPOSIT, amount);
    std::cout << account.getBalance();
    return 0;
}
