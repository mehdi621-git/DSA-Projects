#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <fstream>
#include <ctime>
#include <limits>
#include <algorithm> // For remove_if

using namespace std;

// Define User class first to resolve dependency issues
class User {
protected:
    int user_id;
    string user_name;

public:
    User() : user_id(0), user_name("") {}

    User(int id, const string& name) : user_id(id), user_name(name) {}

    void setId(int id) { user_id = id; }
    void setName(const string& name) { user_name = name; }

    int getId() const { return user_id; }
    string getName() const { return user_name; }
    
    // Add this inside the User class (public section)
    static void addUsers(list<User>& users, int& nextUserId);
    static void viewUsers(list<User>& users);
    static void deleteUser(list<User>& users);
    static void editUser(list<User>& users);
};

// Declaring remaining classes
class Admin;
class Message;
class BackUp;

// Back up Class
class BackUp {
    static fstream File, file;
    static string line;

public:
    BackUp() {
        File.open("backup.csv", ios::in | ios::out | ios::app);
        if (!File.is_open()) {
            cout << "\nError Accessing Backup. Please Retry!" << endl;
        }
        File.flush();
        File.seekg(0);

        if (!getline(File, line))
            File << "USER_IDs,USER_NAMES,MESSAGES,TIMESTAMPS\n";
    }

    string showBackup(list<User>& users) {
        cout << "---Old Chat Messages ---\n";
        string chathistory = "";
        // Reset file read position to beginning after header
        File.clear();
        File.seekg(0);
        // Skip header line
        getline(File, line);

        while (getline(File, line)) {
            if (line.length() <= 5) {
                cerr << "Line too short: " << line << "\n";
                continue;
            }
            
            // 1. Extract first 4 chars as id
            int id = stoi(line.substr(0, 4));   //stoi converts str into int
            string processed = line.substr(5);
        
            // chars till 2nd comma are string name
            // Extract name before processing commas
            size_t commaPos = processed.find(',');
            string name;
            if (commaPos != string::npos) 
                name = processed.substr(0, commaPos);
            else
                name = processed;
            
            // Check if id exists in users
            bool exists = false;
            for (const auto& user : users) {
                if (user.getId() == id) {
                    exists = true;
                    break;
                }
            }
            // 5. If not, add to users
            if (!exists) {
                users.push_back(User(id, name));
            }
            //show backup:
            int commaCount = 1;  // as 1st ',' is handled already above
            for (size_t i = 0; i < processed.length(); ++i) {
                if (processed[i] == ',') {
                    ++commaCount;
                    if (commaCount == 2) {
                        processed.replace(i, 1, " : ");
                        i += 2;
                    }
                    else if (commaCount == 3) {
                        processed.replace(i, 1, "\t\t\t");
                        i += 2;
                    }
                }
            }
            chathistory += processed + "\n";
        }
        return chathistory;
    }

    static void storeBackup(int id, const string& name, const string& msg, time_t timestamp = time(NULL)) {
        if (msg.empty()) {
            cerr << "No msg found" << endl;
            return;
        }
        if (File.is_open()) {
            File.clear();
            File.seekp(0, ios::end); // Move write pointer to end
            File << id << "," << name << "," << msg << "," << ctime(&timestamp);
            // ctime adds a newline already
        }
        else {
            cerr << "Error: File not open" << endl;
        }
    }
    
static void deleteBackup(int id) {
        file.open("backup.csv", ios::in | ios::out);
        if (!file.is_open()) {
            cerr << "\nError Accessing Backup. Please Retry!" << endl; 
            return;
        }
        
        // Create a temporary file for the modified content
        ofstream tempFile("temp_backup.csv");
        if (!tempFile) {
            cerr << "\nError creating temporary file!" << endl;
            file.close();
            return;
        }
        
        // Reset file read position to beginning
        file.clear();
        file.seekg(0);
        
        // Copy header line
        getline(file, line);
        tempFile << line << endl;
        
        // Copy all lines except the one to be deleted
        while (getline(file, line)) {
            if (line.length() <= 5) {
                cerr << "Line too short: " << line << "\n";
                continue;
            }
            
            try {
                // Try to extract the ID safely
                string idStr = line.substr(0, 4);
                // Remove any non-digit characters
                idStr.erase(remove_if(idStr.begin(), idStr.end(), 
                                     [](unsigned char c){ return !isdigit(c); }), 
                           idStr.end());
                
                // Only convert if we have digits
                if (!idStr.empty()) {
                    int lineId = stoi(idStr);
                    // If this is not the line to delete, write it to temp file
                    if (lineId != id) {
                        tempFile << line << endl;
                    }
                } else {
                    // If no valid ID, just copy the line
                    tempFile << line << endl;
                }
            } catch (const std::exception& e) {
                // If any error, just copy the line
                cerr << "Error processing line: " << e.what() << endl;
                tempFile << line << endl;
            }
        }
        
        // Close both files
        File.close();
        file.close();
        tempFile.close();
        
        // Replace the original file with the temp file
        remove("backup.csv");
        rename("temp_backup.csv", "backup.csv");
        
        cout << "User data successfully deleted from backup file." << endl;
    }

    
static void editBackup(int id, const string& newName) {
    ifstream infile("backup.csv");
    ofstream temp("temp.csv");

    if (!infile.is_open() || !temp.is_open()) {
        cerr << "\nError accessing backup file!" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        if (line.length() <= 5) {
            temp << line << '\n'; // Skip invalid lines
            continue;
        }

        size_t firstComma = line.find(',');
        if (firstComma == string::npos) {
            temp << line << '\n';
            continue;
        }

        string idStr = line.substr(0, firstComma);

        try {
            int uid = stoi(idStr);

            if (uid == id) {
                size_t secondComma = line.find(',', firstComma + 1);
                if (secondComma == string::npos) {
                    temp << line << '\n'; // Malformed line
                    continue;
                }

                string rest = line.substr(secondComma); // Message and timestamp
                temp << id << "," << newName << rest << '\n';
            } else {
                temp << line << '\n';
            }

        } catch (invalid_argument& e) {
            cerr << "Invalid ID in line: " << line << '\n';
            temp << line << '\n';
        }
    }
    File.close();
    infile.close();
    temp.close();

    // Replace original backup with edited version
    remove("backup.csv");
    rename("temp.csv", "backup.csv");
}



    ~BackUp() {
        if (File.is_open())
            File.close();
    }
};

// Declare static members of BackUp
fstream BackUp::File;
fstream BackUp::file;
string BackUp::line;

// User class method implementations
void User::addUsers(list<User>& users, int& nextUserId) {
    while (true) {
        cout << "Enter user name to add (or type 'done' to finish adding users): ";
        string name;
        getline(cin, name);

        if (name == "done") {
            if (users.empty()) {
                cout << "You must add at least one user." << endl;
                continue;
            }
            break;
        }

        if (name.empty()) {
            cout << "User name cannot be empty. Try again." << endl;
            continue;
        }

        User newUser;
        newUser.setId(nextUserId++);
        newUser.setName(name);
        users.push_back(newUser);
        
        BackUp::storeBackup(newUser.getId(), newUser.getName(), "Added successfully ..");

        cout << "User '" << name << "' added with ID " << newUser.getId() << "." << endl;
    }
}

void User::viewUsers(list<User>& users) {
    if (users.empty()) {
        cout << "\nNo user found." << endl;
        return;
    }

    cout << "The Active Users are:" << endl;
    cout << "\n_______________________________________________________________\n";

    cout << "\t_____________________________" << endl;
    cout << "\t|USER_ID | USER_NAMES" << endl;
    cout << "\t|________|___________________" << endl;

    for (const auto& user : users) {
        cout << "\t|  " << user.getId() << "  |  " << user.getName() << endl;
        cout << "\t|________|___________________" << endl;
    }
}

void User::deleteUser(list<User>& users) {
    if (users.empty()) {
        cout << "\nNo user found." << endl;
        return;
    }
    
    // Show all active users before editing
    User::viewUsers(users);

    int userid;
    cout << "Enter USER_ID of the user to delete: ";
    cin >> userid;
    cin.ignore(); // Clear the newline from the input buffer

    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getId() == userid) {
            cout<< "User with USER_ID "<< it->getId()<<" and USER_NAME " <<it->getName() <<" deleted successfully!\n";
            
            users.erase(it); // Correct way to delete from list
            
            
            BackUp::deleteBackup(userid);

            return;
        }
    }

    cout << "\nNo user with given id: " << userid << " found." << endl;
}

void User::editUser(list<User>& users) {
    if (users.empty()) {
        cout << "\nNo users found." << endl;
        return;
    }
    
    // Show all active users before editing
    User::viewUsers(users);

    int userid;
    cout << "Enter USER_ID of the user you want to edit: ";
    cin >> userid;
    cin.ignore(); // Clear newline

    string newName;
    cout << "Enter the new name for the user: ";
    getline(cin, newName);
    
    for (auto& user : users) { 
        if (user.getId() == userid) {
            user.setName(newName);
             cout << "User Name of User with ID " << userid << " updated successfully!\n New User Name is " << user.getName()<<endl;
            
            BackUp::editBackup(userid, newName);
            return;
        }
    }

    cout << "\nNo user with given id: " << userid << " found." << endl;
}

// Admin class inherits User
class Admin : public User {
private:
    const int Admin_ID = 911;              // Hardcoded admin ID 
    const string Admin_Name = "bruski";    // Hardcoded admin username  

public:
    Admin() : User() {}

    // Function to verify admin credentials
    bool login(int id, const string& name) {
        return (id == Admin_ID && name == Admin_Name);
    }
    
    int AdminPermissions(string u_name) {
        cout << "\nWelcome, " << u_name << "! Here's what you can do?'\n";
    cout << "\n_______________________________________________________________\n";

        cout << "\n\t1. View All Users";
        cout << "\n\t2. Add New Users";
        cout << "\n\t3. Edit a User";
        cout << "\n\t4. Delete a User";
        cout << "\n\t5. View Previous Chats";
        cout << "\n\t6. Enter Chat-Room";
        cout << "\n\t0. Exit";
    cout << "\n\n_______________________________________________________________\n";

        cout << "\n\nPlease select an option: ";

        int adm_choice;
        cin >> adm_choice;
        cin.ignore();

        return adm_choice;
    }
};

// Message class
class Message {
private:
    int sender_id;
    string sender_name;
    string content;
    time_t timestamp = time(NULL);  //current time
public:
    Message() : sender_id(0), sender_name(""), content("") {}

    Message(int id, const string& name, const string& msg)
        : sender_id(id), sender_name(name), content(msg) {}

    string getFormattedMessage() const {
        return sender_name + ": " + content + "\t\t\t" + ctime(&timestamp);
    }
    
    static string newChat(queue<Message>& messageQueue) {
        cout << "_______________________________________________________________\n";
        cout << "\t--- New Chat Messages ---" << endl;
        cout << "_______________________________________________________________\n";

        queue<Message> tempQueue = messageQueue; // copy to preserve original queue
        string chat = "";
        while (!tempQueue.empty()) {
            Message msg = tempQueue.front();
            tempQueue.pop();
            chat += msg.getFormattedMessage() + "\n";
        }
        
        return chat;
    }
};

// ===== Header & Footer =====
void header(const string& sectionTitle) {
    system("cls"); // or use "clear" on Linux/macOS
    cout << "\n\n==============================================================\n";
    cout << "\t\t\tTERBOT - " << sectionTitle << "\n";
    cout << "==============================================================\n\n\n";
}

void footer() {
    cout << "\n==============================================================\n";
    cout << "\t\tMade by AYESHA_NOREEN CPE-23--01\n";
    cout << "==============================================================\n";
}

// ===== Main Chat Loop function =====
void ChatRoomLoop(list<User>& users, queue<Message>& messageQueue, BackUp& backup) {
    bool running = true;
    while (running) {

        User::viewUsers(users);

        cout << "\n 0. Exit\n";
        cout << "\nSelect user by ID to send a message: ";
        int userChoice;
        cin >> userChoice;
        cin.ignore();

        if (userChoice == 0) {
            running = false;
            cout << "\nExiting chat. Goodbye!\n";
            footer();
            break;
        }

        User* currentUser = nullptr;
        for (auto& user : users)
            if (user.getId() == userChoice)
                currentUser = &user;

        if (!currentUser) {
            cout << "\nInvalid user ID. Try again.\nPress Enter to retry...";
            cin.get();
            continue;
        }

        cout << "\n" << currentUser->getName() << ", enter your message: ";
        string messageText;
        getline(cin, messageText);

        if (messageText.empty()) {
            cout << "\nEmpty message. Try again.\n";
            continue;
        }

        BackUp::storeBackup(currentUser->getId(), currentUser->getName(), messageText);
        messageQueue.push(Message(currentUser->getId(), currentUser->getName(), messageText));
        string msg = Message::newChat(messageQueue);
        cout << msg;
        cout << "\n\n_______________________________________________________________\n";

    }
}

int main() {
    list<User> users;
    queue<Message> messageQueue;
    Admin admin;
    BackUp backup;
    int nextUserId;
    //initiate backup to retrieve users
    string chatHistory = backup.showBackup(users);

    if (!users.empty()) {
        int maxId = 0;
        for (const auto& user : users)
            if (user.getId() > maxId)
                maxId = user.getId();
        nextUserId = maxId + 1;
    } else {
        nextUserId = 1769;
    }

    header("LOGIN");
    cout << "\t\tWelcome to the TerBot\n\tYour handy~candy Terminal Chat System!\n";

    cout << "\n\nGreetings, are you the Admin?? Login to continue!\n";
    int uid;
    string u_name;

    cout << "\n\tAdmin_ID =  ";
    cin >> uid;
    cout << "\tAdmin_Name =  ";
    cin >> u_name;
    cin.ignore();

    if (!admin.login(uid, u_name)) {
        cout << "\nInvalid admin credentials! Access denied.\n";
        footer();
        return 0;
    }

    int adm_choice;
    do {
        header("ADMIN DASHBOARD");
        adm_choice = admin.AdminPermissions(u_name);  

        switch (adm_choice) {
            case 1:
                header("VIEW USERS");
                User::viewUsers(users);
                break;

            case 2:
                header("ADD USERS");
                User::addUsers(users, nextUserId);
                break;

            case 3:
                header("EDIT USER");
                User::editUser(users);
                break;

            case 4:
                header("DELETE USER");
                User::deleteUser(users);
                break;

            case 5:
                header("CHAT HISTORY");
                if (chatHistory.empty())
                    cout << "\nNo backup found!" << endl;
                else 
                    cout << chatHistory << endl;
                break;

            case 6:
            	header("CHAT ROOM");
                ChatRoomLoop(users, messageQueue, backup);
                break;

            case 0:
                cout << "\nExiting program. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

        if (adm_choice != 0) {
            cout << "\nPlease press ENTER to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (adm_choice != 0);

    footer();
    return 0;
}
