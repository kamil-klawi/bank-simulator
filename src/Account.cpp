//
// Created by kamil on 3/29/25.
//

#include <iostream>

#include "../include/Account.h"
#include "../include/GenerateIdNumber.h"

double Account::getBalance() const {
    return this->balance;
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

void Account::performOperation(BankOperation operation, double amount) {
    if (!this->isActive()) {
        throw std::invalid_argument("The account is inactive, so you cannot make deposit or withdraw.");
    }

    if (operation == DEPOSIT) {
        deposit(amount);
        this->transactions_.emplace_back(DEPOSIT, amount, this->balance);
    } else if (operation == WITHDRAW) {
        withdraw(amount);
        this->transactions_.emplace_back(WITHDRAW, amount, this->balance);
    } else {
        std::cout << "Invalid operation!\n";
    }
}

void Account::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("The amount must be greater than 0");
    }

    this->balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("The amount must be greater than 0");
    }

    if (this->balance < amount) {
        throw std::invalid_argument("The balance must be greater than amount");
    }

    this->balance -= amount;
}

void Account::transfer(Account &toAccount, double amount) {
    if (!this->isActive()) {
        throw std::invalid_argument("The account is inactive, so you cannot transfer.");
    }

    if (amount <= 0) {
        std::cout << "The amount must be greater than 0";
    }

    if (this->balance >= amount) {
        this->balance -= amount;
        toAccount.balance += amount;
    } else {
        std::cout << "The balance must be greater or equal amount";
    }
}


void Account::getTransactionHistory() const {
    if (transactions_.empty()) {
        std::cout << "There are no transactions.\n";
    }

    std::cout << "Transaction history: " << this->transactions_.size() << " transactions.\n";
    for (const auto& transaction : this->transactions_) {
        std::cout << "{\n\tOperation: " << (transaction.getOperation() == DEPOSIT ? "DEPOSIT" : "WITHDRAW") << "\n";
        std::cout << "\tAmount: " << transaction.getAmount() << "\n";
        std::cout << "\tAccount balance: " << transaction.getNewBalance() << "\n";
        std::cout << "\tAccount: " << this->getFirstName() << " " << this->getLastName() << "\n";
        std::cout << "\tTimestamp: " << transaction.getTimestamp() << "},\n";
    }
}

Account Account::setAccountDetails(std::string& idNumber, std::string& firstName, std::string& lastName, std::string& email, int& day, int& month, int& year) {
    idNumber = generateIdNumber();
    std::cout << "Enter your first name:\n";
    std::cin >> firstName;
    std::cout << "Enter your last name:\n";
    std::cin >> lastName;
    std::cout << "Enter your address email:\n";
    std::cin >> email;
    std::cout << "Enter your birth day:\n";
    std::cin >> day;
    std::cout << "Enter your birth month:\n";
    std::cin >> month;
    std::cout << "Enter your birth year:\n";
    std::cin >> year;
    return {idNumber, firstName, lastName, email, day, month, year};
}

LoginAndPassword Account::setLoginAndPassword(std::string& login, std::string& password, std::string& confirmPassword, double& balance) {
    std::cout << "Create your login:\n";
    std::cin >> login;

    do {
        std::cout << "Create your password:\n";
        std::cin >> password;
        std::cout << "Confirm password:\n";
        std::cin >> confirmPassword;
        std::cout << "Enter your balance:\n";
        std::cin >> balance;

        if (password != confirmPassword) {
            std::cout << "Passwords do not match. Please try again.\n";
        }
        if (balance < 0) {
            std::cout << "Balance must be non-negative. Please try again.\n";
        }
    } while (password != confirmPassword || balance < 0);

    return {login, password, confirmPassword, balance};
}

Account Account::createBankAccount(std::vector<Account> accounts, Account currentAccount) {
    std::string idNumber, firstName, lastName, email, login, password, confirmPassword;
    int day, month, year;
    double balance;

    Account account = setAccountDetails(idNumber, firstName, lastName, email, day, month, year);
    accounts.push_back(account);

    LoginAndPassword lap = setLoginAndPassword(login, password, confirmPassword, balance);
    currentAccount.createAccount(lap.login, lap.password, lap.confirmPassword, lap.balance);

    return account;
}

std::string Account::getLogin() const {
    return this->login;
}

std::string Account::getPassword() const {
    return this->passwd;
}

