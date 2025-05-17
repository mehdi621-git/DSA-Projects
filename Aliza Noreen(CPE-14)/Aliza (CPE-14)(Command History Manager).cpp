//Command History Manager 
//struct
//stack
//queue
//linear searching
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

// Struct to store command details
struct Command {
    int id;
    string text;
};

int main() {
	 // Stack to store commands for undo operation 
    stack<Command> undoStack;     
    // Queue to store commands for viewing history
    queue<Command> historyQueue; 
    int commandCount = 0;         // to assign unique ID

    int choice;
    string input;
    bool running = true;

    while (running) {
        cout << "\n--- Command History Manager ---\n";
        cout << "1. Add Command\n";
        cout << "2. View Commands\n";
        cout << "3. Undo Last Command\n";
        cout << "4. Search Command\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clears  newline character from input buffer

        if (choice == 1) {
            cout << "Enter command: ";
            getline(cin, input);
            commandCount++;
            Command cmd = {commandCount, input};

            undoStack.push(cmd);
            historyQueue.push(cmd);
            cout << "Command added successfully!\n";

        } else if (choice == 2) {
            if (historyQueue.empty()) {
                cout << "No commands in history.\n";
            } else {
                cout << "Command History:\n";
                queue<Command> tempQueue = historyQueue; // copy to print without deleting
                while (!tempQueue.empty()) {
                    Command cmd = tempQueue.front();
                    cout << cmd.id << ". " << cmd.text << endl;
                    tempQueue.pop();
                }
            }

        } else if (choice == 3) {
            if (undoStack.empty()) {
                cout << "No command to undo.\n";
            } else {
                Command undone = undoStack.top();
                undoStack.pop();

                // remove from history queue
                queue<Command> newQueue;
                while (!historyQueue.empty()) {
                    if (historyQueue.front().id != undone.id) {
                        newQueue.push(historyQueue.front());
                    }
                    historyQueue.pop();
                }
                historyQueue = newQueue;

                cout << "Last command undone: " << undone.text << endl;
            }

        } else if (choice == 4) {
            if (historyQueue.empty()) {
                cout << "No commands to search.\n";
            } else {
                cout << "Enter keyword to search: ";
                getline(cin, input);
                bool found = false;
                 // Copy the queue to preserve original
                queue<Command> tempQueue = historyQueue;
                while (!tempQueue.empty()) {
                    Command cmd = tempQueue.front();
                     // it Checks if keyword is found in the command text
                    if (cmd.text.find(input) != string::npos) {
                        cout << "Found: " << cmd.id << ". " << cmd.text << endl;
                        found = true;
                    }
                    tempQueue.pop();
                }
                if (!found) {
                    cout << "No command matched the keyword.\n";
                }
            }

        } else if (choice == 5) {
            cout << "Goodbye!\n";
            running = false;

        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

