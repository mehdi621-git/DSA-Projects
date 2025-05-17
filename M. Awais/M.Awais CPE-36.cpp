#include <iostream>
#include <string>
#include <iomanip>  
using namespace std;

struct Expense {
    double amount;
    string category;
};

const int MAX_EXPENSES = 100;
Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        cout << "Expense limit reached!\n";
        return;
    }

    cout << "Enter amount: ";
    cin >> expenses[expenseCount].amount;
    cout << "Enter category: ";
    cin.ignore();
    getline(cin, expenses[expenseCount].category);
    
    expenseCount++;
    cout << "Expense added successfully!\n";
}


void sortByAmount(bool ascending = true) {
    for (int i = 0; i < expenseCount-1; i++) {
        for (int j = 0; j < expenseCount-i-1; j++) {
            bool shouldSwap = ascending ? 
                (expenses[j].amount > expenses[j+1].amount) : 
                (expenses[j].amount < expenses[j+1].amount);
            
            if (shouldSwap) {
                swap(expenses[j], expenses[j+1]);
            }
        }
    }
    cout << "Expenses sorted by amount (" << (ascending ? "ascending" : "descending") << ").\n";
}

void displayTotal() {
    double total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    cout << fixed << setprecision(2);
    cout << "Total expenses: $" << total << "\n";
}

void searchByCategory() {
    string category;
    cout << "Enter category to search: ";
    cin.ignore();
    getline(cin, category);
    
    bool found = false;
    for (int i = 0; i < expenseCount; i++) {
        if (expenses[i].category == category) {
            cout << "$" << expenses[i].amount << " - " << expenses[i].category << "\n";
            found = true;
        }
    }
    
    if (!found) {
        cout << "No expenses found in category: " << category << "\n";
    }
}

void displayAll() {
    if (expenseCount == 0) {
        cout << "No expenses recorded yet.\n";
        return;
    }
    
    cout << fixed << setprecision(2);
    cout << "\nAll Expenses:\n";
    for (int i = 0; i < expenseCount; i++) {
        cout << "$" << expenses[i].amount << " - " << expenses[i].category << "\n";
    }
}

int main() {
    int choice;
    
    while (true) {
        cout << "\nBudget Tracking System\n";
        cout << "1. Add Expense\n";
        cout << "2. Sort by Amount (Ascending)\n";
        cout << "3. Sort by Amount (Descending)\n";
        cout << "4. Display Total Expenses\n";
        cout << "5. Search by Category\n";
        cout << "6. View All Expenses\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addExpense(); break;
            case 2: sortByAmount(true); break;
            case 3: sortByAmount(false); break;
            case 4: displayTotal(); break;
            case 5: searchByCategory(); break;
            case 6: displayAll(); break;
            case 0: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
