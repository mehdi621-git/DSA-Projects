#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

vector<Book> library;

void addBook() {
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Book Author: ";
    getline(cin, newBook.author);
    library.push_back(newBook);
    cout << "Book added successfully!\n";
}

void viewBooks() {
    if (library.empty()) {
        cout << "No books in the system.\n";
        return;
    }

    cout << "\nLibrary Catalog:\n";
    for (int i = 0; i < library.size(); ++i) {
        cout << "ID: " << library[i].id
             << ", Title: " << library[i].title
             << ", Author: " << library[i].author << endl;
    }
}

void searchBooks() {
    int choice;
    cout << "\nSearch by:\n1. Title\n2. Author\nEnter choice: ";
    cin >> choice;
    cin.ignore();
    string keyword;
    cout << "Enter search keyword: ";
    getline(cin, keyword);
    bool found = false;

    for (int i = 0; i < library.size(); ++i) {
        if ((choice == 1 && library[i].title.find(keyword) != string::npos) ||
            (choice == 2 && library[i].author.find(keyword) != string::npos)) {
            cout << "ID: " << library[i].id
                 << ", Title: " << library[i].title
                 << ", Author: " << library[i].author << endl;
            found = true;
        }
    }

    if (!found) cout << "No matching books found.\n";
}

void removeBook() {
    int bookId;
    cout << "Enter ID of the book to remove: ";
    cin >> bookId;

    bool found = false;
    for (int i = 0; i < library.size(); ++i) {
        if (library[i].id == bookId) {
            library.erase(library.begin() + i);
            cout << "Book removed successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Library Book Search System ---\n";
        cout << "1. Add Book\n2. View Books\n3. Search Books\n4. Remove Book\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBooks(); break;
            case 4: removeBook(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

