#include "utils.h"
#include <ctime>
#include <iomanip>
#include <sstream>

namespace utils {
    std::string getCurrentDateTime() {
        std::time_t now = std::time(nullptr);
        std::tm* timeinfo = std::localtime(&now);
        char buffer[80];
        std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
        return std::string(buffer);
    }

    bool isValidAmount(double amount) {
        return amount > 0 && amount <= 10000; // Example limit
    }

    std::string formatCurrency(double amount) {
        std::stringstream ss;
        ss << "$" << std::fixed << std::setprecision(2) << amount;
        return ss.str();
    }

    std::string maskAccountNumber(std::string accountNumber) {
        if (accountNumber.length() > 4) {
            return "****" + accountNumber.substr(accountNumber.length() - 4);
        }
        return accountNumber;
    }
}