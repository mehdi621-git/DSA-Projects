#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Weather info structure
struct Weather {
    float temperature;
    float humidity;
    float windSpeed;
};

// Hash map for city-weather storage
unordered_map<string, Weather> cityWeather;

// Function to display weather data
void displayWeather(const string& city) {
    if (cityWeather.find(city) != cityWeather.end()) {
        Weather w = cityWeather[city];
        cout << "\nCity: " << city << endl;
        cout << "Temperature: " << w.temperature << "°C" << endl;
        cout << "Humidity: " << w.humidity << "%" << endl;
        cout << "Wind Speed: " << w.windSpeed << " km/h" << endl;
    } else {
        cout << "City not found!\n";
    }
}

// Function to add or update city weather
void addOrUpdateCityWeather() {
    string city;
    float temp, hum, wind;

    cout << "Enter city name: ";
    cin.ignore(); // Clear buffer
    getline(cin, city);

    cout << "Enter temperature (°C): ";
    cin >> temp;

    cout << "Enter humidity (%): ";
    cin >> hum;

    cout << "Enter wind speed (km/h): ";
    cin >> wind;

    cityWeather[city] = {temp, hum, wind};
    cout << "Weather data added/updated successfully.\n";
}

// Generalized sort function
void sortCitiesBy(const string& criteria) {
    vector<pair<string, Weather>> vec(cityWeather.begin(), cityWeather.end());

    if (criteria == "temperature") {
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second.temperature > b.second.temperature;
        });
    } else if (criteria == "humidity") {
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second.humidity > b.second.humidity;
        });
    } else if (criteria == "wind") {
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second.windSpeed > b.second.windSpeed;
        });
    } else {
        cout << "Invalid sorting criteria!\n";
        return;
    }

    cout << "\nCities sorted by " << criteria << ":\n";
    for (const auto& entry : vec) {
        cout << entry.first << " - ";

        if (criteria == "temperature")
            cout << entry.second.temperature << "°C";
        else if (criteria == "humidity")
            cout << entry.second.humidity << "%";
        else if (criteria == "wind")
            cout << entry.second.windSpeed << " km/h";

        cout << endl;
    }
}

int main() {
    // Sample data
    cityWeather["Lahore"] = {32.5, 65, 12};
    cityWeather["Karachi"] = {30.0, 70, 10};
    cityWeather["Islamabad"] = {28.5, 60, 14};

    int choice;
    string city;

    do {
    	cout << "\n--- Well Come ---\n";
    	cout << "\n--- Muhammad Mujahid Javed ---\n";
        cout << "\n--- Weather Forecast System ---\n";
        cout << "1. Search weather by city\n";
        cout << "2. Sort cities by temperature\n";
        cout << "3. Sort cities by humidity\n";
        cout << "4. Sort cities by wind speed\n";
        cout << "5. Add or update city weather\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter city name: ";
                cin.ignore(); // Clear buffer
                getline(cin, city);
                displayWeather(city);
                break;
            case 2:
                sortCitiesBy("temperature");
                break;
            case 3:
                sortCitiesBy("humidity");
                break;
            case 4:
                sortCitiesBy("wind");
                break;
            case 5:
                addOrUpdateCityWeather();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
