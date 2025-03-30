//
// Created by kamil on 3/29/25.
//

#include <iostream>

#include "../include/Account.h"

double Account::getBalance() const {
    return balance;
}

bool Account::isActive() const {
    return this->active == true;
}

void Account::createAccount(std::string& login, std::string& passwd, std::string& confirmPasswd, double balance) {
    this->login = login;
    this->passwd = passwd;
    this->confirmPasswd = confirmPasswd;
    this->balance = balance;
}

void Account::editAccount(Account& account) {
    if (!account.isActive()) {
        throw std::invalid_argument("The account is inactive, so you cannot change the data.");
    }

    std::vector<std::string> options = {
        "First name",
        "Last name",
        "E-mail address",
        "Birth date",
        "Login",
        "Password",
    };

    std::cout << "What do you want to edit?\n";
    for (int i = 0; i < options.size(); i++) {
        std::cout << i << ". " << options[i] << std::endl;
    }

    int choice;
    std::cout << "Option: ";
    std::cin >> choice;

    std::string firstName, lastName, email, login, passwd;
    int day, month, year;

    switch (choice) {
        case 0:
            std::cout << "Enter your new first name: ";
            std::cin >> firstName;
            account.setFirstName(firstName);
            break;
        case 1:
            std::cout << "Enter your new last name: ";
            std::cin >> lastName;
            account.setLastName(lastName);
            break;
        case 2:
            std::cout << "Enter your new e-mail address: ";
            std::cin >> email;
            account.setEmail(email);
            break;
        case 3:
            std::cout << "Enter your new birth day: ";
            std::cin >> day;
            std::cout << "Enter your new birth month: ";
            std::cin >> month;
            std::cout << "Enter your new birth year: ";
            std::cin >> year;
            account.setBirthday(day, month, year);
            break;
        case 4:
            std::cout << "Enter your new login: ";
            std::cin >> login;
            account.setLogin(login);
            break;
        case 5:
            std::cout << "Enter your new password: ";
            std::cin >> passwd;
            account.setPasswd(passwd);
            break;
        default:
            std::cout << "Invalid option!" << std::endl;
    }
}

void Account::deleteAccount() {
    this->active = false;
}

void Account::activateAccount() {
    this->active = true;
}

void Account::setLogin(std::string& login) {
    this->login = login;
}

void Account::setPasswd(std::string& passwd) {
    this->passwd = passwd;
}
