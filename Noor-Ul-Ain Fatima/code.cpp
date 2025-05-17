#include <iostream>
#include <cmath>   // for NAN and isnan()
#include <cstdlib> // for system()
using namespace std;

// Recursive factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive power (a^b)
int power(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

// Arithmetic functions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero." << endl;
        return NAN;
    }
    return static_cast<double>(a) / b;
}

// Menu display
void displayMenu() {
    cout << "----- Recursive Calculator Menu -----\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Factorial (Recursive)\n";
    cout << "6. Power (a^b, Recursive)\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice, a, b;

    do {
        system("cls"); // Clear the console screen on Windows

        displayMenu();
        cin >> choice;

        system("cls"); // Clear screen before showing result

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result of Addition: " << add(a, b) << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result of Subtraction: " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result of Multiplication: " << multiply(a, b) << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                {
                    double res = divide(a, b);
                    if (!isnan(res))
                        cout << "Result of Division: " << res << endl;
                    // If division by zero, error already printed inside divide()
                }
                break;
            case 5:
                cout << "Enter a number for factorial: ";
                cin >> a;
                cout << "Result of Factorial: " << factorial(a) << endl;
                break;
            case 6:
                cout << "Enter base: ";
                cin >> a;
                cout << "Enter exponent: ";
                cin >> b;
                cout << "Result of Power: " << power(a, b) << endl;
                break;
            case 0:
                cout << "Exiting Calculator. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore(); // Ignore leftover newline from previous input
            cin.get();    // Wait for Enter key
        }

    } while (choice != 0);

    return 0;
}

