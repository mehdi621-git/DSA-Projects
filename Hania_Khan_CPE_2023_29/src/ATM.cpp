#include "ATM.h"
#include <iostream>

ATM::ATM(int initialCapacity) : capacity(initialCapacity), accountCount(0) {
    accounts = new Account*[capacity];
    for (int i = 0; i < capacity; i++) {
        accounts[i] = nullptr;
    }
}

ATM::~ATM() {
    for (int i = 0; i < accountCount; i++) {
        delete accounts[i];
    }
    delete[] accounts;
}

void ATM::addAccount(Account* account) {
    if (accountCount == capacity) {
        resizeAccountArray();
    }
    accounts[accountCount++] = account;
}

Account* ATM::findAccount(std::string accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i]->getAccountNumber() == accountNumber) {
            return accounts[i];
        }
    }
    return nullptr;
}

void ATM::enqueueDeposit(Account* account) {
    depositQueue.push(account);
    processDeposits();
}

void ATM::enqueueWithdrawal(Account* account) {
    withdrawalQueue.push(account);
    processWithdrawals();
}

void ATM::processDeposits() {
    while (!depositQueue.empty()) {
        Account* account = depositQueue.front();
        // In a real system, we would process the deposit here
        depositQueue.pop();
    }
}

void ATM::processWithdrawals() {
    while (!withdrawalQueue.empty()) {
        Account* account = withdrawalQueue.front();
        // In a real system, we would process the withdrawal here
        withdrawalQueue.pop();
    }
}

void ATM::resizeAccountArray() {
    int newCapacity = capacity * 2;
    Account** newArray = new Account*[newCapacity];
    
    for (int i = 0; i < accountCount; i++) {
        newArray[i] = accounts[i];
    }
    
    delete[] accounts;
    accounts = newArray;
    capacity = newCapacity;
}

void ATM::displayAllAccounts() const {
    std::cout << "\nAll Accounts in ATM System:" << std::endl;
    for (int i = 0; i < accountCount; i++) {
        std::cout << "Account #" << i+1 << ": " 
                  << accounts[i]->getAccountNumber() 
                  << ", Balance: " << accounts[i]->getBalance() << std::endl;
    }
}