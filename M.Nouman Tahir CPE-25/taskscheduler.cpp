#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Task {
    string description;
    int priority;
    string deadline;
    bool completed;
};

Task tasks[MAX];
int count = 0;

void addTask() {
    if (count >= MAX) {
        cout << "Task list is full!\n";
        return;
    }

    cin.ignore();
    cout << "Enter description: ";
    getline(cin, tasks[count].description);
    cout << "Enter priority (1=High, 2=Medium, 3=Low): ";
    cin >> tasks[count].priority;
    cout << "Enter deadline (e.g., 2025-05-15): ";
    cin >> tasks[count].deadline;

    tasks[count].completed = false;
    count++;
    cout << "Task added.\n";
}

void displayByPriority() {
    if (count == 0) {
        cout << "No tasks added.\n";
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tasks[j].priority > tasks[j + 1].priority) {
                swap(tasks[j], tasks[j + 1]);
            }
        }
    }

    cout << "\nDescription\tPriority\n";
    for (int i = 0; i < count; i++) {
        cout << tasks[i].description << "\t" << tasks[i].priority << endl;
    }
}

void displayByDeadline() {
    if (count == 0) {
        cout << "No tasks added.\n";
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tasks[j].deadline > tasks[j + 1].deadline) {
                swap(tasks[j], tasks[j + 1]);
            }
        }
    }

    cout << "\nDescription\tDeadline\n";
    for (int i = 0; i < count; i++) {
        cout << tasks[i].description << "\t" << tasks[i].deadline << endl;
    }
}

void markCompleted() {
    string keyword;
    cin.ignore();
    cout << "Enter keyword to mark task as completed: ";
    getline(cin, keyword);
    for (int i = 0; i < count; i++) {
        if (tasks[i].description.find(keyword) != string::npos) {
            tasks[i].completed = true;
            cout << "Task marked as completed.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void searchTask() {
    string keyword;
    cin.ignore();
    cout << "Enter keyword to search: ";
    getline(cin, keyword);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (tasks[i].description.find(keyword) != string::npos) {
            cout << "\nDescription: " << tasks[i].description;
            cout << "\nPriority: " << tasks[i].priority;
            cout << "\nDeadline: " << tasks[i].deadline;
            cout << "\nStatus: " << (tasks[i].completed ? "Completed" : "Pending") << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Task not found.\n";
    }
}

void deleteTask() {
    string keyword;
    cin.ignore();
    cout << "Enter keyword to delete task: ";
    getline(cin, keyword);
    for (int i = 0; i < count; i++) {
        if (tasks[i].description.find(keyword) != string::npos) {
            for (int j = i; j < count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            count--;
            cout << "Task deleted.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void executeNextTask() {
    int highestPriority = 4; // Higher than any valid priority
    int taskIndex = -1;

    for (int i = 0; i < count; i++) {
        if (!tasks[i].completed && tasks[i].priority < highestPriority) {
            highestPriority = tasks[i].priority;
            taskIndex = i;
        }
    }

    if (taskIndex == -1) {
        cout << "No pending tasks to execute.\n";
        return;
    }

    cout << "\nNext task to execute:\n";
    cout << "Description: " << tasks[taskIndex].description << "\n";
    cout << "Priority: " << tasks[taskIndex].priority << "\n";
    cout << "Deadline: " << tasks[taskIndex].deadline << "\n";

    char choice;
    cout << "Mark this task as completed? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        tasks[taskIndex].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Task left pending.\n";
    }
}

void menu() {
    int choice;
    do {
        cout << "\n==== Task Scheduler ====\n";
        cout << "1. Add Task\n";
        cout << "2. Display by Priority\n";
        cout << "3. Display by Deadline\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Search Task\n";
        cout << "6. Delete Task\n";
        cout << "7. Execute Next Task by Priority\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: displayByPriority(); break;
            case 3: displayByDeadline(); break;
            case 4: markCompleted(); break;
            case 5: searchTask(); break;
            case 6: deleteTask(); break;
            case 7: executeNextTask(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}