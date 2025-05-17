#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct LineNode {
    string line;
    LineNode* next;

    LineNode(const string& l) {
        line = l;
        next = NULL; 
    }
};

struct Operation {
    string type; 
    string text;
};

class TextEditor {
private:
    LineNode* head;
    stack<Operation> undoStack;

public:
    TextEditor() {
        head = NULL;
    }

    void typeLine(const string& text) {
        LineNode* newNode = new LineNode(text);

        if (head == NULL) {
            head = newNode;
        } else {
            LineNode* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        undoStack.push({"add", text});
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "No actions to undo.\n";
            return;
        }

        Operation lastOp = undoStack.top();
        undoStack.pop();

        if (lastOp.type == "add") {
            removeLastLine();
        }
    }

    void viewContent() {
        if (head == NULL) {
            cout << "[Document is empty]\n";
            return;
        }

        LineNode* temp = head;
        int lineNo = 1;
        while (temp != NULL) {
            cout << lineNo++ << ": " << temp->line << endl;
            temp = temp->next;
        }
    }

private:
    void removeLastLine() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        LineNode* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }
};

int main() {
    TextEditor editor;
    int choice;
    string input;

    do {
        cout << "\n--- Simple Text Editor ---\n";
        cout << "1. Type new line\n";
        cout << "2. Undo last change\n";
        cout << "3. View current content\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter text: ";
                getline(cin, input);
                editor.typeLine(input);
                break;
            case 2:
                editor.undo();
                break;
            case 3:
                editor.viewContent();
                break;
            case 4:
                cout << "Exiting editor.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

