#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <cctype>

using namespace std;

// Function prototypes
void mergeSort(char* names[], int left, int right);
void merge(char* names[], int left, int mid, int right);

void merge(char* names[], int left, int mid, int right) {
    vector<char*> L(names + left, names + mid + 1);
    vector<char*> R(names + mid + 1, names + right + 1);
    
    int i = 0, j = 0, k = left;
    
    while (i < L.size() && j < R.size())
        names[k++] = strcmp(L[i], R[j]) <= 0 ? L[i++] : R[j++];
    
    while (i < L.size()) names[k++] = L[i++];
    while (j < R.size()) names[k++] = R[j++];
}

void mergeSort(char* names[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(names, left, mid);
    mergeSort(names, mid + 1, right);
    merge(names, left, mid, right);
}

void processNames() {
    const int MAX_NAMES = 50;
    const int MAX_LENGTH = 100;
    char* names[MAX_NAMES] = {NULL};
    char choice;

    do {
s        int n;
        cout << "\nEnter number of names (20-50): ";
        
        while (!(cin >> n) || n < 20 || n > MAX_NAMES) {
            cout << "Invalid input. Please enter between 20 and 50: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        cout << "Enter the names:\n";
        for (int i = 0; i < n; i++) {
            names[i] = new char[MAX_LENGTH];
            cout << "Name " << (i + 1) << ": ";
            cin.getline(names[i], MAX_LENGTH);
        }

        mergeSort(names, 0, n - 1);

        cout << "\nSorted names (A-Z):\n";
        for (int i = 0; i < n; i++) {
            cout << names[i] << '\n';
            delete[] names[i];
            names[i] = NULL;
        }

        cout << "\nProcess another list? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (toupper(choice) == 'Y');

    // Final cleanup
    for (int i = 0; i < MAX_NAMES; i++) {
        if (names[i]) {
            delete[] names[i];
            names[i] = NULL;
        }
    }
}

int main() {
    processNames();
    cout << "\nProgram exited. Goodbye!\n";
    return 0;
}

