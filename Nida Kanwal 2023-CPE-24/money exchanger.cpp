#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Currency {
    string symbol;
    string name;
    float rate;
};

Currency currencies[MAX];
int count = 0;

// Add a new currency
void addCurrency() {
    if (count >= MAX) {
        cout << "Currency list is full!\n";
        return;
    }
    cout << "Enter symbol: ";
    cin >> currencies[count].symbol;
    cout << "Enter name: ";
    cin >> currencies[count].name;
    cout << "Enter exchange rate to USD: ";
    cin >> currencies[count].rate;
    count++;
    cout << "Currency added successfully.\n";
}

// Update exchange rate
void updateRate() {
    string sym;
    cout << "Enter symbol to update: ";
    cin >> sym;
    for (int i = 0; i < count; i++) {
        if (currencies[i].symbol == sym) {
            cout << "Old rate: " << currencies[i].rate << "\nEnter new rate: ";
            cin >> currencies[i].rate;
            cout << "Rate updated.\n";
            return;
        }
    }
    cout << "Currency not found.\n";
}

// Convert currency
void convertCurrency() {
    string from, to;
    float amount;
    cout << "From currency symbol: ";
    cin >> from;
    cout << "To currency symbol: ";
    cin >> to;
    cout << "Amount: ";
    cin >> amount;

    float rateFrom = -1, rateTo = -1;
    for (int i = 0; i < count; i++) {
        if (currencies[i].symbol == from) rateFrom = currencies[i].rate;
        if (currencies[i].symbol == to) rateTo = currencies[i].rate;
    }

    if (rateFrom == -1 || rateTo == -1) {
        cout << "Currency not found.\n";
        return;
    }

    float usd = amount / rateFrom;
    float result = usd * rateTo;
    cout << amount << " " << from << " = " << result << " " << to << endl;
}

// Sort by name
void sortByName() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (currencies[j].name > currencies[j + 1].name) {
                swap(currencies[j], currencies[j + 1]);
            }
        }
    }
    cout << "Sorted by name.\n";
}

// Sort by rate
void sortByRate() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (currencies[j].rate > currencies[j + 1].rate) {
                swap(currencies[j], currencies[j + 1]);
            }
        }
    }
    cout << "Sorted by rate.\n";
}

// Binary search by symbol (requires sorted array)
int binarySearch(string sym) {
    int low = 0, high = count - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (currencies[mid].symbol == sym) return mid;
        else if (currencies[mid].symbol < sym) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Search currency
void searchCurrency() {
    string query;
    cout << "Enter currency symbol or name: ";
    cin >> query;

    // Search by symbol
    sortByName(); // ensure sorted before binary search
    int index = binarySearch(query);
    if (index != -1) {
        cout << "Found: " << currencies[index].symbol << " | " << currencies[index].name << " | Rate: " << currencies[index].rate << endl;
        return;
    }

    // Linear search by name
    for (int i = 0; i < count; i++) {
        if (currencies[i].name == query) {
            cout << "Found: " << currencies[i].symbol << " | " << currencies[i].name << " | Rate: " << currencies[i].rate << endl;
            return;
        }
    }

    cout << "Currency not found.\n";
}

// Display all
void displayAll() {
    if (count == 0) {
        cout << "No currencies added yet.\n";
        return;
    }

    cout << "\nSymbol\tName\t\tRate (to USD)\n";
    for (int i = 0; i < count; i++) {
        cout << currencies[i].symbol << "\t" << currencies[i].name << "\t\t" << currencies[i].rate << endl;
    }
}

// Menu
void menu() {
    int choice;
    do {
        cout << "\n====== Currency Exchange Tracker ======\n";
        cout << "1. Add Currency\n";
        cout << "2. Update Rate\n";
        cout << "3. Convert Currency\n";
        cout << "4. Search Currency\n";
        cout << "5. Sort by Name\n";
        cout << "6. Sort by Rate\n";
        cout << "7. Display All\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.clear();             // Handle input errors
        cin.ignore(1000, '\n');  // Clear extra input

        switch (choice) {
            case 1: addCurrency(); break;
            case 2: updateRate(); break;
            case 3: convertCurrency(); break;
            case 4: searchCurrency(); break;
            case 5: sortByName(); break;
            case 6: sortByRate(); break;
            case 7: displayAll(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);
}

// Main function
int main() {
    menu();
    return 0;
}

