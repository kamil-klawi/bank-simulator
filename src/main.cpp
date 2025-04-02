#include <iostream>
#include <random>

#include "../include/Account.h"
#include "../include/Helpers.h"

int main() {
    int choice;
    std::string login, passwd;
    std::vector<Account> accounts;
    Account currentAccount;
    const std::vector<std::string> topics = {
        "Create an account",
        "Login to account",
        "Activate account",
        "Delete account",
        "Exiting the application"
    };

    do {
        std::cout << "What do you want to do?\n";
        for (int i = 0; i < topics.size(); i++) {
            std::cout << i + 1 << ". " << topics[i] << "\n";
        }
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                currentAccount = Account::createBankAccount(accounts, currentAccount);
                accounts.push_back(currentAccount);
                break;
            case 2:
                if (checkIfAccountsEmpty(accounts)) {
                    continue;
                }
                for (const Account& account : accounts) {
                    std::cout << account.getIdNumber() << "\n";
                    std::cout << account.getFirstName() << " " << account.getLastName() << "\n";
                    std::cout << account.getEmail() << "\n";
                    std::cout << account.getBirthday() << "\n";
                }
                break;
            case 3:
                if (checkIfAccountsEmpty(accounts)) {
                    continue;
                }

                if (checkIfUserLoggedIn(currentAccount)) {
                    continue;
                }

                currentAccount.activateAccount();
                break;
            case 4:
                if (checkIfAccountsEmpty(accounts)) {
                    continue;
                }

                if (checkIfUserLoggedIn(currentAccount)) {
                    continue;
                }

                currentAccount.deleteAccount();
                break;
            case 5:
                std::cout << "You are exiting the app!\n";
                std::cout << "Thank you for using the app! Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}
