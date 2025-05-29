#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find and display duplicate elements and their frequencies
void findDuplicates(const vector<int>& nums) {
    unordered_map<int, int> frequency;

    // Count frequency of each element (using hashing)
    for (int num : nums) {
        frequency[num]++;
    }

    // Display duplicates
    cout << "\nDuplicate elements:\n";
    bool found = false;
    for (const auto& pair : frequency) {
        if (pair.second > 1) {
            cout << pair.first << " (frequency: " << pair.second << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No duplicate elements found.\n";
    }
}

int main() {
    int n;

    // Input size of the list
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);  // Using vector (DSA: dynamic array)

    // Input values from the user
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Call function to find duplicates
    findDuplicates(nums);

    return 0;
}