#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bid {
    string username;
    double amount;
};

class BiddingSystem {
private:
    vector<Bid> bids;

public:
    void placeBid(string user, double amt) {
        bids.push_back({user, amt});
        cout << "Bid placed by " << user << " for $" << amt << endl;
    }

    void showHighestBid() {
        if (bids.empty()) {
            cout << "No bids yet.\n";
            return;
        }
        Bid maxBid = *max_element(bids.begin(), bids.end(), [](const Bid& a, const Bid& b) {
            return a.amount < b.amount;
        });
        cout << "Highest Bid: " << maxBid.username << " - $" << maxBid.amount << endl;
    }

    void viewAllBids() {
        if (bids.empty()) {
            cout << "No bids to show.\n";
            return;
        }
        cout << "All Bids:\n";
        for (const auto& bid : bids) {
            cout << bid.username << " - $" << bid.amount << endl;
        }
    }

    void sortBids() {
    cout << "Before sorting:\n";
    for (auto& b : bids) cout << b.username << " - $" << b.amount << endl;

    sort(bids.begin(), bids.end(), [](const Bid& a, const Bid& b) {
        return a.amount > b.amount;
    });

    cout << "\nAfter sorting in Descending order:\n";
    for (auto& b : bids) cout << b.username << " - $" << b.amount << endl;
}

    void endAuction() {
        if (bids.empty()) {
            cout << "No winner. No bids placed.\n";
        } else {
            sortBids();
            cout << "Auction ended. Winner: " << bids[0].username << " with $" << bids[0].amount << endl;
        }
    }
};

int main() {
    BiddingSystem auction;
    int choice;
    string name;
    double amount;

    do {
        cout << "\n--- Bidding System Menu ---\n";
        cout << "1. Place a new bid\n2. Show highest bid\n3. View all bids\n4. Sort bids\n5. End auction\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter your name without space: ";
                cin >> name;
                cout << "Enter bid amount: ";
                cin >> amount;
                auction.placeBid(name, amount);
                break;
            case 2:
                auction.showHighestBid();
                break;
            case 3:
                auction.viewAllBids();
                break;
            case 4:
                auction.sortBids();
                break;
            case 5:
                auction.endAuction();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
