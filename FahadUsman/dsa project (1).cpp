#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Patient {
    string name;
    int age;
    string symptoms;
    bool emergency;
};

// Simple menu function
void showMenu() {
    cout << "\nHospital Queue System\n";
    cout << "1. Add Regular Patient\n";
    cout << "2. Add Emergency Patient\n";
    cout << "3. Serve Next Patient\n";
    cout << "4. View All Patients\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    queue<Patient> regularQueue;
    queue<Patient> priorityQueue; // For emergencies and elderly
    int choice;
    
    while(true) {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        if(choice == 1 || choice == 2) {
            // Add patient
            Patient p;
            bool isEmergency = (choice == 2);
            
            cout << "Enter name: ";
            getline(cin, p.name);
            cout << "Enter age: ";
            cin >> p.age;
            cin.ignore();
            cout << "Enter symptoms: ";
            getline(cin, p.symptoms);
            p.emergency = isEmergency;
            
            if(isEmergency || p.age >= 60) {
                priorityQueue.push(p);
                cout << "Added to priority queue.\n";
            } else {
                regularQueue.push(p);
                cout << "Added to regular queue.\n";
            }
        }
        else if(choice == 3) {
            // Serve next patient
            if(!priorityQueue.empty()) {
                Patient p = priorityQueue.front();
                cout << "\nServing priority patient:\n";
                cout << "Name: " << p.name << "\nAge: " << p.age 
                     << "\nSymptoms: " << p.symptoms << "\n\n";
                priorityQueue.pop();
            }
            else if(!regularQueue.empty()) {
                Patient p = regularQueue.front();
                cout << "\nServing regular patient:\n";
                cout << "Name: " << p.name << "\nAge: " << p.age 
                     << "\nSymptoms: " << p.symptoms << "\n\n";
                regularQueue.pop();
            }
            else {
                cout << "No patients in queue.\n";
            }
        }
        else if(choice == 4) {
            // View all patients
            cout << "\nPriority Queue Patients:\n";
            queue<Patient> tempPrio = priorityQueue;
            while(!tempPrio.empty()) {
                Patient p = tempPrio.front();
                cout << p.name << " (" << p.age << ") - " 
                     << p.symptoms << (p.emergency ? " [EMERGENCY]" : "") << endl;
                tempPrio.pop();
            }
            
            cout << "\nRegular Queue Patients:\n";
            queue<Patient> tempReg = regularQueue;
            while(!tempReg.empty()) {
                Patient p = tempReg.front();
                cout << p.name << " (" << p.age << ") - " << p.symptoms << endl;
                tempReg.pop();
            }
            
            if(priorityQueue.empty() && regularQueue.empty()) {
                cout << "No patients in queues.\n";
            }
        }
        else if(choice == 5) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    
    return 0;
}
