#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int marks;
    Node* next;

    Node(string n, int m) {
        name = n;
        marks = m;
        next = NULL;
    }
};

class StudentList {
private:
    Node* head;

    // Helper to merge two sorted lists
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result = NULL;

        if (a->marks >= b->marks) {
            result = a;
            result->next = merge(a->next, b);
        } else {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }

    // Helper to split the list
    void split(Node* source, Node** front, Node** back) {
        Node* slow = source;
        Node* fast = source->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }

    // Recursive merge sort
    void mergeSort(Node** headRef) {
        Node* head = *headRef;
        if (!head || !head->next)
            return;

        Node* a;
        Node* b;

        split(head, &a, &b);
        mergeSort(&a);
        mergeSort(&b);

        *headRef = merge(a, b);
    }

public:
    StudentList() {
        head = NULL;
    }

    void addStudent(string name, int marks) {
        Node* newNode = new Node(name, marks);
        newNode->next = head;
        head = newNode;
    }

    void sortStudents() {
        mergeSort(&head);
    }

    void displayRankList() {
        Node* temp = head;
        int rank = 1;
        cout << "\nRank\tName\tMarks\n";
        while (temp != NULL) {
            cout << rank << "\t" << temp->name << "\t" << temp->marks << endl;
            temp = temp->next;
            rank++;
        }
    }

    void searchStudent(string targetName) {
        Node* temp = head;
        int rank = 1;
        while (temp != NULL) {
            if (temp->name == targetName) {
                cout << targetName << "'s rank is: " << rank << " with marks: " << temp->marks << endl;
                return;
            }
            temp = temp->next;
            rank++;
        }
        cout << targetName << " not found in the list.\n";
    }
};
int main() {
    StudentList sl;
    int n;
    string name;
    int marks;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of student " << i+1 << ": ";
        cin >> name;
        cout << "Enter marks of " << name << ": ";
        cin >> marks;
        sl.addStudent(name, marks);
    }

    sl.sortStudents();
    sl.displayRankList();

    cout << "\nSearch for a student's rank.\nEnter name: ";
    cin >> name;
    sl.searchStudent(name);

    return 0;
}

