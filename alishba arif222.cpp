#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Node structure for linked list
struct Node {
    string note;
    Node* next;
};

// Function to add a new note
void addNote(Node** head) {
    string note;
    cout << "Enter your note: ";
    cin.ignore(); // Ignore newline character left in input buffer
    getline(cin, note);
    Node* newNode = new Node();
    newNode->note = note;
    newNode->next = *head;
    *head = newNode;
    cout << "Note added successfully!" << endl;
}

// Function to view all notes
void viewNotes(Node* head) {
    if (head == NULL) {
        cout << "No notes available." << endl;
        return;
    }
    int noteNumber = 1;
    while (head != NULL) {
        cout << noteNumber << ". " << head->note << endl;
        head = head->next;
        noteNumber++;
    }
}

// Function to update a note
void updateNote(Node* head) {
    if (head == NULL) {
        cout << "No notes available." << endl;
        return;
    }
    int noteNumber;
    cout << "Enter note number to update: ";
    cin >> noteNumber;
    int currentNoteNumber = 1;
    Node* currentNode = head;
    while (currentNode != NULL && currentNoteNumber < noteNumber) {
        currentNode = currentNode->next;
        currentNoteNumber++;
    }
    if (currentNode == NULL|| currentNoteNumber != noteNumber) {
        cout << "Invalid note number." << endl;
        return;
    }
    string newNote;
    cout << "Enter new note: ";
    cin.ignore(); // Ignore newline character left in input buffer
    getline(cin, newNote);
    currentNode->note = newNote;
    cout << "Note updated successfully!" << endl;
}

// Function to delete a note
void deleteNote(Node** head) {
    if (*head == NULL) {
        cout << "No notes available." << endl;
        return;
    }
    int noteNumber;
    cout << "Enter note number to delete: ";
    cin >> noteNumber;
    if (noteNumber == 1) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        cout << "Note deleted successfully!" << endl;
        return;
    }
    int currentNoteNumber = 1;
    Node* currentNode = *head;
    while (currentNode->next != NULL && currentNoteNumber < noteNumber - 1) {
        currentNode = currentNode->next;
        currentNoteNumber++;
    }
    if (currentNode->next == NULL || currentNoteNumber != noteNumber - 1) {
        cout << "Invalid note number." << endl;
        return;
    }
    Node* temp = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete temp;
    cout << "Note deleted successfully!" << endl;
}

// Function to save notes to file
void saveNotes(Node* head) {
    ofstream file("notes.txt");
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;}
    while (head != NULL) {
        file << head->note << endl;
        head = head->next;
    }
    file.close();
    cout << "Notes saved successfully!" << endl;
}

// Function to load notes from file
void loadNotes(Node** head) {
    ifstream file("notes.txt");
    if (!file.is_open()) {
        return;
    }
    string note;
    while (getline(file, note)) {
        Node* newNode = new Node();
        newNode->note = note;
        newNode->next = *head;
        *head = newNode;
    }
    file.close();
}

int main() {
    Node* head = NULL;
    loadNotes(&head);

    while (true) {
        cout << "Note-Taking App" << endl;
        cout << "1. Add Note" << endl;
        cout << "2. View Notes" << endl;
        cout << "3. Update Note" << endl;
        cout << "4. Delete Note" << endl;
        cout << "5. Save Notes" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNote(&head);
                break;
            case 2:
                viewNotes(head);
                break;}
            }
        }
    
