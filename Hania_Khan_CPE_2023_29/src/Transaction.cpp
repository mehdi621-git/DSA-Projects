#include "Transaction.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

Transaction::Transaction(std::string type, double amount) 
    : type(type), amount(amount), timestamp(std::time(nullptr)), next(nullptr) {}

std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTimestamp() const {
    std::tm* timeinfo = std::localtime(&timestamp);
    char buffer[80];
    std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}

Transaction* Transaction::getNext() const {
    return next;
}

void Transaction::setNext(Transaction* nextTransaction) {
    next = nextTransaction;
}

void Transaction::display() const {
    std::cout << std::left << std::setw(15) << getTimestamp()
              << std::setw(12) << type 
              << std::setw(10) << amount << std::endl;
}