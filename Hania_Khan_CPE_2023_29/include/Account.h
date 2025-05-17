#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Transaction.h"

class Account {
private:
    std::string accountNumber;
    std::string pin;
    double balance;
    Transaction* transactionHistory; // Linked list head

public:
    Account(std::string accNum, std::string pin, double initialBalance);
    ~Account();

    std::string getAccountNumber() const;
    bool verifyPin(std::string inputPin) const;
    double getBalance() const;
    void updateBalance(double amount);
    
    void addTransaction(Transaction* newTransaction);
    void displayTransactionHistory() const;
};

#endif // ACCOUNT_H