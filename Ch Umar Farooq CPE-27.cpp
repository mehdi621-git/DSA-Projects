#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Entry {
    string word;
    string meaning;
};

// Comparison function for sorting
bool compareEntries(const Entry& a, const Entry& b) {
    return a.word < b.word;
}

vector<Entry> dictionary;

void addWord() {
    Entry newEntry;
    cout << "Enter word: ";
    cin >> newEntry.word;
    cout << "Enter meaning: ";
    cin.ignore();
    getline(cin, newEntry.meaning);
    dictionary.push_back(newEntry);
    cout << "Word added!\n";
}

void deleteWord() {
    string word;
    cout << "Enter word to delete: ";
    cin >> word;
    
    for(int i = 0; i < dictionary.size(); i++) {
        if(dictionary[i].word == word) {
            dictionary.erase(dictionary.begin() + i);
            cout << "Word deleted!\n";
            return;
        }
    }
    cout << "Word not found!\n";
}

void searchWord() {
    string word;
    cout << "Enter word to search: ";
    cin >> word;
    
    for(vector<Entry>::const_iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
        if(it->word == word) {
            cout << it->word << ": " << it->meaning << "\n";
            return;
        }
    }
    cout << "Word not found!\n";
}

void sortDictionary() {
    sort(dictionary.begin(), dictionary.end(), compareEntries);
    cout << "Dictionary sorted!\n";
}

void viewAll() {
    if(dictionary.empty()) {
        cout << "Dictionary is empty!\n";
        return;
    }
    
    cout << "\nAll Entries:\n";
    for(vector<Entry>::const_iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
        cout << it->word << ": " << it->meaning << "\n";
    }
}

int main() {
    int choice;
    
    while(true) {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add Word\n";
        cout << "2. Delete Word\n";
        cout << "3. Search Word\n";
        cout << "4. Sort Dictionary\n";
        cout << "5. View All\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addWord(); break;
            case 2: deleteWord(); break;
            case 3: searchWord(); break;
            case 4: sortDictionary(); break;
            case 5: viewAll(); break;
            case 0: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
