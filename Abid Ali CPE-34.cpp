#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
struct Birthday {
    string name;
    int day;
    int month;
};

void addBirthday(Birthday* list, int* size) {
    if (*size >= MAX) {
        cout << "List is full.\n";
        return;
    }

    cout << "Enter name: ";
    cin.ignore(); 
    getline(cin, list[*size].name);

    cout << "Enter birth day (1-31): ";
    cin >> list[*size].day;

    cout << "Enter birth month (1-12): ";
    cin >> list[*size].month;

    (*size)++;
    cout << "Birthday added successfully!\n";
}
void viewAll(Birthday* list, int size) {
    if (size == 0) {
        cout << "No birthdays added yet.\n";
        return;
    }

    cout << "\nList of Birthdays:\n";
    for (int i = 0; i < size; i++) {
        cout << list[i].name << " - " << list[i].day << "/" << list[i].month << "\n";
    }
}

void searchByDate(Birthday* list, int size) {
    int day, month;
    cout << "Enter day to search: ";
    cin >> day;
    cout << "Enter month to search: ";
    cin >> month;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (list[i].day == day && list[i].month == month) {
            cout << list[i].name << " has a birthday on " << day << "/" << month << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No birthdays found on that date.\n";
    }
}
void sortBirthdays(Birthday* list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[j].month < list[i].month || 
               (list[j].month == list[i].month && list[j].day < list[i].day)) {
                swap(list[i], list[j]);
            }
        }
    }
    cout << "Birthdays sorted by date.\n";
}

int main() {
    Birthday birthdays[MAX];
    int size = 0;
    int choice;

    do {
        cout << "\n--- Birthday Manager ---\n";
        cout << "1. Add Birthday\n";
        cout << "2. View All Birthdays\n";
        cout << "3. Search by Date\n";
        cout << "4. Sort Birthdays by Date\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addBirthday(birthdays, &size); break;
            case 2: viewAll(birthdays, size); break;
            case 3: searchByDate(birthdays, size); break;
            case 4: sortBirthdays(birthdays, size); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 5);

    return 0;
}

