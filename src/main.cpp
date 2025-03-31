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
    std::string idNumber2 = "FES34294";
    std::string firstName2 = "Alexander";
    std::string lastName2 = "Smith";
    std::string email2 = "alexander.smith@example.com";

    Account account(idNumber, firstName, lastName, email, day, month, year);
    Account account2(idNumber2, firstName2, lastName2, email2, day, month, year);

    std::string login = "john-doe";
    std::string passwd = "john123";
    std::string confirmPasswd = "john123";
    std::string login2 = "alexander-smith";
    std::string passwd2 = "alexander123";
    std::string confirmPasswd2 = "alexander123";

    double balance = 1000;
    double amount = 500;

    account.createAccount(login, passwd, confirmPasswd, balance);
    account2.createAccount(login2, passwd2, confirmPasswd2, balance);
    account.activateAccount();
    account2.activateAccount();

    std::cout << "Balance account 1: " << account.getBalance() << "$\n";
    std::cout << "Balance account 2: " << account2.getBalance() << "$\n";

    account.transfer(account2, amount);

    std::cout << "Balance account 1: " << account.getBalance() << "$\n";
    std::cout << "Balance account 2: " << account2.getBalance() << "$\n";

    return 0;
}
