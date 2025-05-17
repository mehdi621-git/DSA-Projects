#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
private:
    std::string type; // "Deposit" or "Withdrawal"
    double amount;
    std::time_t timestamp;
    Transaction* next; // For linked list

public:
    Transaction(std::string type, double amount);
    
    std::string getType() const;
    double getAmount() const;
    std::string getTimestamp() const;
    
    Transaction* getNext() const;
    void setNext(Transaction* nextTransaction);
    
    void display() const;
};

#endif // TRANSACTION_H