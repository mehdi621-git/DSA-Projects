#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string number;
};

class PhoneBook {
private:
    vector<Contact> contacts;

    bool isDuplicate(const string& name, const string& number) {
        for (size_t i = 0; i < contacts.size(); ++i) {
            if (contacts[i].name == name || contacts[i].number == number) {
                return true;
            }
        }
        return false;
    }

public:
    void addContact(const string& name, const string& number) {
        if (isDuplicate(name, number)) {
            cout << "Contact already exists.\n";
            return;
        }
        Contact newContact;
        newContact.name = name;
        newContact.number = number;
        contacts.push_back(newContact);
        cout << "Contact added successfully.\n";
    }

    void searchContact(const string& query) {
        bool found = false;
        for (size_t i = 0; i < contacts.size(); ++i) {
            if (contacts[i].name == query || contacts[i].number == query) {
                cout << "Found: " << contacts[i].name << " - " << contacts[i].number << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No contact found.\n";
        }
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "Phonebook is empty.\n";
            return;
        }
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << contacts[i].name << " - " << contacts[i].number << endl;
        }
    }
};

int main() {
    PhoneBook phonebook;
    int choice;
    string name, number, query;

    while (true) {
        cout << "\nPhonebook Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Display All Contacts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Flush newline

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Number: ";
                getline(cin, number);
                phonebook.addContact(name, number);
                break;
            case 2:
                cout << "Enter Name or Number to Search: ";
                getline(cin, query);
                phonebook.searchContact(query);
                break;
            case 3:
                phonebook.displayContacts();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}

