#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

class CityDistanceTracker {
private:
    vector<string> cities;
    vector<vector<int> > distanceMatrix; // Fixed: space between > >
    int INF; // Changed: non-static initialization

public:
    CityDistanceTracker() {
        INF = numeric_limits<int>::max(); // Initialize in constructor
    }

    // Add a new city to the tracker
    void addCity(const string& cityName) {
        // Check if city already exists
        if (find(cities.begin(), cities.end(), cityName) != cities.end()) {
            cout << "City " << cityName << " already exists." << endl;
            return;
        }

        cities.push_back(cityName);
        
        // Resize the distance matrix (using traditional for loop)
        for (size_t i = 0; i < distanceMatrix.size(); ++i) {
            distanceMatrix[i].push_back(INF);
        }
        
        // Add new row for the new city
        vector<int> newRow(cities.size(), INF);
        distanceMatrix.push_back(newRow);
        
        // Distance from a city to itself is 0
        distanceMatrix.back().back() = 0;
        
        cout << "City " << cityName << " added successfully." << endl;
    }

    // Add or update distance between two cities
    void addDistance(const string& city1, const string& city2, int distance) {
        int index1 = findCityIndex(city1);
        int index2 = findCityIndex(city2);
        
        if (index1 == -1 || index2 == -1) {
            cout << "One or both cities not found." << endl;
            return;
        }
        
        if (distance < 0) {
            cout << "Distance cannot be negative." << endl;
            return;
        }
        
        distanceMatrix[index1][index2] = distance;
        distanceMatrix[index2][index1] = distance;
        cout << "Distance between " << city1 << " and " << city2 
             << " set to " << distance << " km." << endl;
    }

    // View distance between two cities
    void viewDistance(const string& city1, const string& city2) {
        int index1 = findCityIndex(city1);
        int index2 = findCityIndex(city2);
        
        if (index1 == -1 || index2 == -1) {
            cout << "One or both cities not found." << endl;
            return;
        }
        
        if (distanceMatrix[index1][index2] == INF) {
            cout << "No direct path between " << city1 << " and " << city2 << "." << endl;
        } else {
            cout << "Direct distance between " << city1 << " and " << city2 
                 << " is " << distanceMatrix[index1][index2] << " km." << endl;
        }
    }

    // Find shortest path between two cities (using Dijkstra's algorithm)
    void findShortestPath(const string& startCity, const string& endCity) {
        int start = findCityIndex(startCity);
        int end = findCityIndex(endCity);
        
        if (start == -1 || end == -1) {
            cout << "One or both cities not found." << endl;
            return;
        }
        
        if (start == end) {
            cout << "Start and end cities are the same. Distance is 0 km." << endl;
            return;
        }
        
        int n = cities.size();
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);
        vector<int> prev(n, -1);
        
        dist[start] = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            int u = minDistanceIndex(dist, visited);
            if (u == -1) break; // No reachable nodes left
            
            visited[u] = true;
            
            for (int v = 0; v < n; ++v) {
                if (!visited[v] && distanceMatrix[u][v] != INF && 
                    dist[u] + distanceMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + distanceMatrix[u][v];
                    prev[v] = u;
                }
            }
        }
        
        if (dist[end] == INF) {
            cout << "No path exists between " << startCity << " and " << endCity << "." << endl;
        } else {
            cout << "Shortest distance between " << startCity << " and " << endCity 
                 << " is " << dist[end] << " km." << endl;
            
            // Print path
            vector<string> path;
            for (int at = end; at != -1; at = prev[at]) {
                path.push_back(cities[at]);
            }
            reverse(path.begin(), path.end());
            
            cout << "Path: ";
            for (size_t i = 0; i < path.size(); ++i) {
                if (i != 0) cout << " -> ";
                cout << path[i];
            }
            cout << endl;
        }
    }

    // Display all cities and their direct connections
    void displayAllRoutes() {
        if (cities.empty()) {
            cout << "No cities in the tracker." << endl;
            return;
        }
        
        // Header row
        cout << setw(15) << "Cities";
        for (size_t i = 0; i < cities.size(); ++i) {
            cout << setw(10) << cities[i];
        }
        cout << endl;
        
        // Distance matrix
        for (size_t i = 0; i < cities.size(); ++i) {
            cout << setw(15) << cities[i];
            for (size_t j = 0; j < cities.size(); ++j) {
                if (distanceMatrix[i][j] == INF) {
                    cout << setw(10) << "-";
                } else {
                    cout << setw(10) << distanceMatrix[i][j];
                }
            }
            cout << endl;
        }
    }

private:
    // Helper function to find city index
    int findCityIndex(const string& cityName) {
        vector<string>::iterator it; // Explicit iterator declaration
        it = find(cities.begin(), cities.end(), cityName);
        if (it != cities.end()) {
            return distance(cities.begin(), it);
        }
        return -1;
    }

    // Helper function for Dijkstra's algorithm
    int minDistanceIndex(const vector<int>& dist, const vector<bool>& visited) {
        int minDist = INF;
        int minIndex = -1;
        
        for (size_t i = 0; i < dist.size(); ++i) {
            if (!visited[i] && dist[i] <= minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        
        return minIndex;
    }
};

// Menu interface
void displayMenu() {
    cout << "\nCity Distance Tracker\n";
    cout << "1. Add a city\n";
    cout << "2. Add/update distance between two cities\n";
    cout << "3. View direct distance between two cities\n";
    cout << "4. Find shortest path between two cities\n";
    cout << "5. Display all routes\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CityDistanceTracker tracker;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline character
        
        string city1, city2;
        int distance;
        
        switch (choice) {
            case 1:
                cout << "Enter city name to add: ";
                getline(cin, city1);
                tracker.addCity(city1);
                break;
                
            case 2:
                cout << "Enter first city: ";
                getline(cin, city1);
                cout << "Enter second city: ";
                getline(cin, city2);
                cout << "Enter distance (km): ";
                cin >> distance;
                tracker.addDistance(city1, city2, distance);
                break;
                
            case 3:
                cout << "Enter first city: ";
                getline(cin, city1);
                cout << "Enter second city: ";
                getline(cin, city2);
                tracker.viewDistance(city1, city2);
                break;
                
            case 4:
                cout << "Enter starting city: ";
                getline(cin, city1);
                cout << "Enter destination city: ";
                getline(cin, city2);
                tracker.findShortestPath(city1, city2);
                break;
                
            case 5:
                tracker.displayAllRoutes();
                break;
                
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
