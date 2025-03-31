//
// Created by kamil on 3/31/25.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

#include "BankOperations.h"

class Transaction {
public:
    Transaction(BankOperation operation, double amount, double newBalance);
    BankOperation getOperation() const;
    double getAmount() const;
    double getNewBalance() const;
    std::string getTimestamp() const;
private:
    BankOperation operation_;
    double amount_;
    double newBalance_;
    std::string timestamp_;
};

#endif //TRANSACTION_H
