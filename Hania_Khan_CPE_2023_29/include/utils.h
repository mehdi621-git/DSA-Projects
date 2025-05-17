#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace utils {
    std::string getCurrentDateTime();
    bool isValidAmount(double amount);
    std::string formatCurrency(double amount);
    std::string maskAccountNumber(std::string accountNumber);
}

#endif // UTILS_H