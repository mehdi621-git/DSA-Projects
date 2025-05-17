#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string>      
#include <sstream>     
using namespace std;

class SmartParkingSystem {
private:
    int totalSlots;
    vector<bool> slots; 
    stack<int> history; 
    queue<int> waitQueue; 
    map<int, string> parkedCars; 

public:
    SmartParkingSystem(int n) {
        totalSlots = n;
        slots.resize(n, false);
    }

    void parkCar(string plateNumber) {
        for (int i = 0; i < totalSlots; ++i) {
            if (!slots[i]) {
                slots[i] = true;
                parkedCars[i] = plateNumber;
                history.push(i);
                cout << "Car " << plateNumber << " parked at slot " << i + 1 << ".\n";
                return;
            }
        }

        cout << "Parking full. Adding to waiting queue.\n";
        waitQueue.push(plateNumber.length()); // using length as dummy ID
    }

    void removeCar(int slot) {
        if (slot < 1 || slot > totalSlots || !slots[slot - 1]) {
            cout << "Invalid or empty slot.\n";
            return;
        }

        string plateNumber = parkedCars[slot - 1];
        slots[slot - 1] = false;
        parkedCars.erase(slot - 1);
        cout << "Car " << plateNumber << " removed from slot " << slot << ".\n";

        if (!waitQueue.empty()) {
            cout << "Assigning slot " << slot << " to waiting car.\n";
            
            // ? Safe fallback using stringstream if to_string ever fails
            stringstream ss;
            ss << "WAIT-" << waitQueue.front();
            string newCar = ss.str();

            waitQueue.pop();
            slots[slot - 1] = true;
            parkedCars[slot - 1] = newCar;
            history.push(slot - 1);
            cout << "Car " << newCar << " parked at slot " << slot << ".\n";
        }
    }

    void showSlots() {
        cout << "\nParking Slot Status:\n";
        for (int i = 0; i < totalSlots; ++i) {
            cout << "Slot " << i + 1 << ": ";
            if (slots[i]) cout << "Occupied (" << parkedCars[i] << ")\n";
            else cout << "Empty\n";
        }
    }

    void showHistory() {
        cout << "\nVehicle History (latest on top):\n";
        stack<int> temp = history;
        while (!temp.empty()) {
            int slot = temp.top(); temp.pop();
            if (parkedCars.count(slot))
                cout << "Slot " << slot + 1 << ": " << parkedCars[slot] << endl;
        }
    }
};

// ?? Driver Code
int main() {
    int n;
    cout << "Enter total parking slots: ";
    cin >> n;

    SmartParkingSystem parking(n);
    int choice;
    do {
        cout << "\n1. Park Car\n2. Remove Car\n3. Show Slots\n4. Show History\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string plate;
            cout << "Enter car plate number: ";
            cin >> plate;
            parking.parkCar(plate);
            break;
        }
        case 2: {
            int slot;
            cout << "Enter slot to remove car from: ";
            cin >> slot;
            parking.removeCar(slot);
            break;
        }
        case 3:
            parking.showSlots();
            break;
        case 4:
            parking.showHistory();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

