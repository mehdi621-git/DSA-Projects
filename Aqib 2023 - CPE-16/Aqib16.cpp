#include <iostream>
using namespace std;

const int MAX = 100;

struct Student {
    char name[50];
    char roll_no[20];
    float marks;
};

// Custom string comparison function
int compareStr(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return a[i] - b[i];
        i++;
    }
    return a[i] - b[i];
}

// Custom string equality check
bool isEqual(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

void inputStudents(Student students[], int &n) {
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // Clear newline

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.getline(students[i].name, 50);
        cout << "Roll Number: ";
        cin.getline(students[i].roll_no, 20);
        cout << "Marks: ";
        cin >> students[i].marks;
        cin.ignore(); // Clear newline
    }
}

void displayStudents(Student students[], int n) {
    cout << "\nStudent Records:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << students[i].name
             << ", Roll No: " << students[i].roll_no
             << ", Marks: " << students[i].marks << endl;
    }
}

void sortByName(Student students[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (compareStr(students[j].name, students[j+1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
}

void sortByRoll(Student students[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (compareStr(students[j].roll_no, students[j+1].roll_no) > 0) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
}

void sortByMarks(Student students[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (students[j].marks < students[j+1].marks) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
}

void searchStudent(Student students[], int n) {
    int choice;
    char query[50];
    cout << "\nSearch by:\n1. Name\n2. Roll Number\nEnter choice: ";
    cin >> choice;
    cin.ignore();
    cout << "Enter search term: ";
    cin.getline(query, 50);

    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((choice == 1 && isEqual(students[i].name, query)) ||
            (choice == 2 && isEqual(students[i].roll_no, query))) {
            cout << "Student found: Name: " << students[i].name
                 << ", Roll No: " << students[i].roll_no
                 << ", Marks: " << students[i].marks << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student not found.\n";
}

int main() {
    Student students[MAX];
    int n = 0;
    int option;

    inputStudents(students, n);

    do {
        cout << "\nMenu:\n1. Display Students\n2. Sort by Name\n3. Sort by Roll Number\n4. Sort by Marks\n5. Search Student\n6. Exit\nEnter your choice: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                displayStudents(students, n);
                break;
            case 2:
                sortByName(students, n);
                cout << "Sorted by name.\n";
                break;
            case 3:
                sortByRoll(students, n);
                cout << "Sorted by roll number.\n";
                break;
            case 4:
                sortByMarks(students, n);
                cout << "Sorted by marks.\n";
                break;
            case 5:
                searchStudent(students, n);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (option != 6);

    return 0;
}