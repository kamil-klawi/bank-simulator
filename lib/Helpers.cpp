//
// Created by kamil on 4/2/25.
//

#include <iostream>
#include <vector>

#include "../include/Account.h"

bool checkIfAccountsEmpty(const std::vector<Account>& accounts) {
    if (accounts.empty()) {
        std::cout << "There are no accounts\n";
        return true;
    }
    return false;
}

bool checkIfUserLoggedIn(const Account& currentAccount) {
    if (currentAccount.getIdNumber().empty()) {
        std::cout << "You are not logged in\n";
        return false;
    }
    return true;
}
