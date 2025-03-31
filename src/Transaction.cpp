//
// Created by kamil on 3/31/25.
//

#include <ctime>

#include "../include/Transaction.h"

Transaction::Transaction(BankOperation operation, double amount, double newBalance) {
    this->operation_ = operation;
    this->amount_ = amount;
    this->newBalance_ = newBalance;

    time_t now = time(0);
    char* date = ctime(&now);
    this->timestamp_ = std::string(date);
}

BankOperation Transaction::getOperation() const {
    return this->operation_;
}

double Transaction::getAmount() const {
    return this->amount_;
}

std::string Transaction::getTimestamp() const {
    return this->timestamp_;
}

double Transaction::getNewBalance() const {
    return this->newBalance_;
}
