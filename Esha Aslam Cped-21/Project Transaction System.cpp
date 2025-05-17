#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TransactionSystem {
private:
    double balance = 0;
    vector<pair<string, double>> history;

public:
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Amount must be positive.\n";
            return;
        }
        balance += amount;
        history.push_back({"deposit", amount});
        cout << "Deposited $" << amount << ". Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            cout << "Not enough balance.\n";
            return;
        }
        balance -= amount;
        history.push_back({"withdraw", amount});
        cout << "Withdrew $" << amount << ". Balance: $" << balance << endl;
    }

    void showHistory() {
        if (history.empty()) {
            cout << "No transactions yet.\n";
            return;
        }
        cout << "Transaction History:\n";
        for (size_t i = 0; i < history.size(); ++i) {
            cout << i + 1 << ". " << history[i].first << ": $" << history[i].second << endl;
        }
    }

    void undoLast() {
        if (history.empty()) {
            cout << "No transaction to undo.\n";
            return;
        }

        auto last = history.back();
        history.pop_back();

        if (last.first == "deposit") {
            balance -= last.second;
            cout << "Undo deposit of $" << last.second << ". New balance: $" << balance << endl;
        } else if (last.first == "withdraw") {
            balance += last.second;
            cout << "Undo withdrawal of $" << last.second << ". New balance: $" << balance << endl;
        }
    }

    void showBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
    TransactionSystem system;
    int choice;
    double amount;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Show History\n4. Undo Last\n5. Show Balance\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                system.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                system.withdraw(amount);
                break;
            case 3:
                system.showHistory();
                break;
            case 4:
                system.undoLast();
                break;
            case 5:
                system.showBalance();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
