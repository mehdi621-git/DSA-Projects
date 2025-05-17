#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int TOTAL_SEATS = 50;

struct Passenger {
    string name;
    int age;
    int seatNumber;
};

class ReservationSystem {
private:
    bool seats[TOTAL_SEATS];
    vector<Passenger> passengers;
    vector<Passenger> waitlist;

public:
    ReservationSystem() {
        for (int i = 0; i < TOTAL_SEATS; i++) {
            seats[i] = false;
        }
    }

    void bookTicket() {
        Passenger p;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter name: ";
        getline(cin, p.name);

        bool validAge = false;
        while (!validAge) {
            cout << "Enter age: ";
            if (cin >> p.age) {
                if (p.age > 0 && p.age < 120) {
                    validAge = true;
                } else {
                    cout << "Age must be between 1 and 120. Please try again.\n";
                }
            } else {
                cout << "Invalid input. Please enter a numeric age.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        for (int i = 0; i < TOTAL_SEATS; i++) {
            if (!seats[i]) {
                p.seatNumber = i + 1;
                seats[i] = true;
                passengers.push_back(p);
                cout << "Booked seat " << p.seatNumber << " for " << p.name << endl;
                return;
            }
        }

        waitlist.push_back(p);
        cout << "No seats available. Added to waitlist.\n";
    }

    void cancelTicket() {
        int seat;
        cout << "Enter seat to cancel (1-" << TOTAL_SEATS << "): ";
        while (!(cin >> seat) || seat < 1 || seat > TOTAL_SEATS) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid seat! Enter a number between 1 and " << TOTAL_SEATS << ": ";
        }

        if (!seats[seat - 1]) {
            cout << "Seat not booked!\n";
            return;
        }

        seats[seat - 1] = false;

        // Corrected iterator-based removal
        vector<Passenger>::iterator it;
        for (it = passengers.begin(); it != passengers.end(); ++it) {
            if (it->seatNumber == seat) {
                passengers.erase(it);
                break;
            }
        }

        if (!waitlist.empty()) {
            Passenger next = waitlist.front();
            waitlist.erase(waitlist.begin());
            next.seatNumber = seat;
            seats[seat - 1] = true;
            passengers.push_back(next);
            cout << "Assigned seat " << seat << " to waitlisted passenger: " << next.name << endl;
        } else {
            cout << "Seat " << seat << " is now available.\n";
        }
    }

    void showBookings() {
        if (passengers.empty()) {
            cout << "\nNo current bookings.\n";
            return;
        }

        cout << "\nCurrent Bookings:\n";
        for (size_t i = 0; i < passengers.size(); i++) {
            cout << "Seat " << passengers[i].seatNumber << ": " << passengers[i].name 
                 << " (Age: " << passengers[i].age << ")\n";
        }
    }

    void viewSeatMap() {
        cout << "\nSeat Map (X = booked, O = available):\n";
        for (int i = 0; i < TOTAL_SEATS; i++) {
            cout << (seats[i] ? "X " : "O ");
            if ((i + 1) % 10 == 0)
                cout << endl;
        }
    }

    void viewWaitlist() {
        if (waitlist.empty()) {
            cout << "\nWaitlist is empty.\n";
            return;
        }

        cout << "\nCurrent Waitlist:\n";
        for (size_t i = 0; i < waitlist.size(); i++) {
            cout << i + 1 << ". " << waitlist[i].name << " (Age: " << waitlist[i].age << ")\n";
        }
    }
};

int main() {
    ReservationSystem system;
    int choice;

    while (true) {
        cout << "\n--- Ticket Reservation System ---\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Bookings\n";
        cout << "4. View Seat Map\n";
        cout << "5. View Waitlist\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number (0-5).\n";
            continue;
        }

        switch (choice) {
            case 1: system.bookTicket(); break;
            case 2: system.cancelTicket(); break;
            case 3: system.showBookings(); break;
            case 4: system.viewSeatMap(); break;
            case 5: system.viewWaitlist(); break;
            case 0:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 0 and 5.\n";
        }
    }
}
