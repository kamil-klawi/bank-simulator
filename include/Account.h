//
// Created by kamil on 3/29/25.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    Account(double balance) : balance(balance) {}
    double getBalance() const;
private:
    double balance;
};

#endif //ACCOUNT_H
