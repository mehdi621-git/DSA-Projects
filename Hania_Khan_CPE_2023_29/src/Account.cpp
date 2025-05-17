#include "Account.h"
#include "Transaction.h"
#include <iostream>

Account::Account(std::string accNum, std::string pin, double initialBalance) 
    : accountNumber(accNum), pin(pin), balance(initialBalance), transactionHistory(nullptr) {}

Account::~Account() {
    // Clean up transaction history linked list
    Transaction* current = transactionHistory;
    while (current != nullptr) {
        Transaction* next = current->getNext();
        delete current;
        current = next;
    }
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

bool Account::verifyPin(std::string inputPin) const {
    return pin == inputPin;
}

double Account::getBalance() const {
    return balance;
}

void Account::updateBalance(double amount) {
    balance += amount;
}

void Account::addTransaction(Transaction* newTransaction) {
    if (transactionHistory == nullptr) {
        transactionHistory = newTransaction;
    } else {
        newTransaction->setNext(transactionHistory);
        transactionHistory = newTransaction;
    }
}

void Account::displayTransactionHistory() const {
    std::cout << "\nTransaction History for Account: " << accountNumber << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    Transaction* current = transactionHistory;
    while (current != nullptr) {
        current->display();
        current = current->getNext();
    }
    
    std::cout << "----------------------------------------" << std::endl;
}