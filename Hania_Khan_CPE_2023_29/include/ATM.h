#ifndef ATM_H
#define ATM_H

#include <queue>
#include "Account.h"

class ATM {
private:
    Account** accounts; // Array of accounts
    int accountCount;
    int capacity;
    
    std::queue<Account*> depositQueue;
    std::queue<Account*> withdrawalQueue;

    void processDeposits();
    void processWithdrawals();
    void resizeAccountArray();

public:
    ATM(int initialCapacity = 10);
    ~ATM();

    void addAccount(Account* account);
    Account* findAccount(std::string accountNumber);
    
    void enqueueDeposit(Account* account);
    void enqueueWithdrawal(Account* account);
    
    void displayAllAccounts() const; // For admin purposes
};

#endif // ATM_H