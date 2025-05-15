#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_HISTORY = 100;
string history[MAX_HISTORY];
int historyCount = 0;

void showMainMenu();
void lengthConverter();
void temperatureConverter();
void weightConverter();
void timeConverter();
void saveToHistory(const string &entry);
void saveToFile();
void showHistory();
void clearScreen();

int main() {
    int choice;

    do {
        showMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lengthConverter(); break;
            case 2: temperatureConverter(); break;
            case 3: weightConverter(); break;
            case 4: timeConverter(); break;
            case 5: showHistory(); break;
            case 6: saveToFile(); break;
            case 7: clearScreen(); break;
            case 0: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}

void showMainMenu() {
    cout << "\n\n<--- Multi-Purpose Unit Converter ---><---By M.Sami Ullah[2023-CPE-17]--->\n";
    cout << "[1]. Length Converter\n";
    cout << "[2]. Temperature Converter\n";
    cout << "[3]. Weight Converter\n";
    cout << "[4]. Time Converter\n";
    cout << "[5]. Show Conversion History\n";
    cout << "[6]. Save History to File\n";
    cout << "[7]. Clear Screen\n";
    cout << "[0]. Exit\n";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void saveToHistory(const string &entry) {
    if (historyCount < MAX_HISTORY) {
        history[historyCount++] = entry;
    }
}

void saveToFile() {
    ofstream file("conversion_history.txt");
    if (file.is_open()) {
        for (int i = 0; i < historyCount; ++i) {
            file << history[i] << endl;
        }
        file.close();
        cout << "History saved to conversion_history.txt\n";
    } else {
        cout << "Error opening file for writing.\n";
    }
}

void showHistory() {
    cout << "\n<--- Conversion History --->\n";
    for (int i = 0; i < historyCount; ++i) {
        cout << history[i] << endl;
    }
}

void lengthConverter() {
    int choice;
    double value, result;

    cout << "\n\n<--- Length Converter --->\n\n";
    cout << "[1]. Centimeter to Inch\n";
    cout << "[2]. Centimeter to Kilometer\n";
    cout << "[3]. Centimeter to Meter\n";
    cout << "[4]. Centimeter to Millimeter\n";
    cout << "[5]. Inch to Centimeter\n";
    cout << "[6]. Inch to Kilometer\n";
    cout << "[7]. Inch to Meter\n";
    cout << "[8]. Inch to Millimeter\n";
    cout << "[9]. Kilometer to Centimeter\n";
    cout << "[10].Kilometer to Inch\n";
    cout << "[11].Kilometer to Meter\n";
    cout << "[12].Kilometer to Millimeter\n";
    cout << "[13].Meter to Centimeter\n";
    cout << "[14].Meter to Inch\n";
    cout << "[15].Meter to Kilometer\n";
    cout << "[16].Meter to Millimeter\n";
    cout << "[17].Millimeter to Centimeter\n";
    cout << "[18].Millimeter to Inch\n";
    cout << "[19].Millimeter to Kilometer\n";
    cout << "[20].Millimeter to Meter\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    switch (choice) {
        case 1:  result = value / 2.54;            cout << value << " cm = " << result << " in\n"; break;
        case 2:  result = value / 100000;          cout << value << " cm = " << result << " km\n"; break;
        case 3:  result = value / 100;             cout << value << " cm = " << result << " m\n"; break;
        case 4:  result = value * 10;              cout << value << " cm = " << result << " mm\n"; break;
        case 5:  result = value * 2.54;            cout << value << " in = " << result << " cm\n"; break;
        case 6:  result = value / 39370.1;         cout << value << " in = " << result << " km\n"; break;
        case 7:  result = value * 0.0254;          cout << value << " in = " << result << " m\n"; break;
        case 8:  result = value * 25.4;            cout << value << " in = " << result << " mm\n"; break;
        case 9:  result = value * 100000;          cout << value << " km = " << result << " cm\n"; break;
        case 10: result = value * 39370.1;         cout << value << " km = " << result << " in\n"; break;
        case 11: result = value * 1000;            cout << value << " km = " << result << " m\n"; break;
        case 12: result = value * 1e6;             cout << value << " km = " << result << " mm\n"; break;
        case 13: result = value * 100;             cout << value << " m = " << result << " cm\n"; break;
        case 14: result = value / 0.0254;          cout << value << " m = " << result << " in\n"; break;
        case 15: result = value / 1000;            cout << value << " m = " << result << " km\n"; break;
        case 16: result = value * 1000;            cout << value << " m = " << result << " mm\n"; break;
        case 17: result = value / 10;              cout << value << " mm = " << result << " cm\n"; break;
        case 18: result = value / 25.4;            cout << value << " mm = " << result << " in\n"; break;
        case 19: result = value / 1e6;             cout << value << " mm = " << result << " km\n"; break;
        case 20: result = value / 1000;            cout << value << " mm = " << result << " m\n"; break;
        default: cout << "Invalid choice.\n"; return;
    }

    saveToHistory("Length: " + to_string(value) + " = " + to_string(result));
}

void temperatureConverter() {
    int choice;
    double value, result;

    cout << "\n\n<--- Temperature Converter --->\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    if (choice == 1) {
        result = (value * 9/5) + 32;
        cout << value << " °C = " << fixed << setprecision(2) << result << " °F\n";
        saveToHistory(to_string(value) + " C = " + to_string(result) + " F");
    } else if (choice == 2) {
        result = (value - 32) * 5/9;
        cout << value << " °F = " << fixed << setprecision(2) << result << " °C\n";
        saveToHistory(to_string(value) + " F = " + to_string(result) + " C");
    } else {
        cout << "Invalid choice.\n";
    }
}

void weightConverter() {
    int choice;
    double value, result;

    cout << "\n\n<--- Weight Converter --->\n";
    cout << "1. Kilogram to Pound\n";
    cout << "2. Pound to Kilogram\n";
    cout << "3. Kilogram to Gram\n";
    cout << "4. Gram to Kilogram\n";
    cout << "5. Pound to Gram\n";
    cout << "6. Gram to Pound\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    switch (choice) {
        case 1: result = value * 2.20462;
                cout << value << " kg = " << result << " lbs\n";
                saveToHistory(to_string(value) + " kg = " + to_string(result) + " lbs");
                break;
        case 2: result = value / 2.20462;
                cout << value << " lbs = " << result << " kg\n";
                saveToHistory(to_string(value) + " lbs = " + to_string(result) + " kg");
                break;
        case 3: result = value * 1000;
                cout << value << " kg = " << result << " g\n";
                saveToHistory(to_string(value) + " kg = " + to_string(result) + " g");
                break;
        case 4: result = value / 1000;
                cout << value << " g = " << result << " kg\n";
                saveToHistory(to_string(value) + " g = " + to_string(result) + " kg");
                break;
        case 5: result = value * 453.592;
                cout << value << " lbs = " << result << " g\n";
                saveToHistory(to_string(value) + " lbs = " + to_string(result) + " g");
                break;
        case 6: result = value / 453.592;
                cout << value << " g = " << result << " lbs\n";
                saveToHistory(to_string(value) + " g = " + to_string(result) + " lbs");
                break;
        default: cout << "Invalid choice.\n";
    }
}

void timeConverter() {
    int choice;
    double value, result;

    cout << "\n\n<--- Time Converter --->\n";
    cout << "[1]. Hours to Minutes\n";
    cout << "[2]. Hours to Seconds\n";
    cout << "[3]. Minutes to Hours\n";
    cout << "[4]. Minutes to Seconds\n";
    cout << "[5]. Seconds to Hours\n";
    cout << "[6]. Seconds to Minutes\n";
    
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter value: ";
    cin >> value;

    switch (choice) {
        case 1: result = value * 60;              cout << value << " hours = " << result << " min\n"; break;
        case 2: result = value * 3600;            cout << value << " hours = " << result << " sec\n"; break;
        case 3: result = value / 60;              cout << value << " min = " << result << " hours\n"; break;
        case 4: result = value * 60;              cout << value << " min = " << result << " sec\n"; break;
        case 5: result = value / 3600;            cout << value << " sec = " << result << " hours\n"; break;
        case 6: result = value / 60;              cout << value << " sec = " << result << " min\n"; break;
        
        default: cout << "Invalid choice.\n"; return;
    }

    saveToHistory("Time: " + to_string(value) + " = " + to_string(result));
}