//
// Created by kamil on 4/2/25.
//

#ifndef HELPERS_H
#define HELPERS_H

#include <vector>

#include "Account.h"

bool checkIfAccountsEmpty(const std::vector<Account>& accounts);
bool checkIfUserLoggedIn(const Account& currentAccount);

#endif //HELPERS_H
