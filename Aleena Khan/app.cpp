#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Globally Declaring a size of 100, which is no.of participants that can be stored in this system
const int MAX_PARTICIPANTS = 100;

//Making a Participant class
class Participant {
    public:
    string name;
    int score;
};

//Globally Declaring all the functions at the start of my code to avoid any scope errors
void AddData(Participant DataArray[], int &count);
void ArrangeInDescendingOrder(Participant DataArray[], int count);
void DisplayData(const Participant DataArray[], int count);
void SearchParticipant(const Participant DataArray[],int count);

//main function where the actual code starts executing
int main() {
    //Declaring an Array named 'DataArray' of the 'Participant' class
    Participant DataArray[MAX_PARTICIPANTS];
    
    //Declaring a variable just to keep track of participants 
    int count = 0;
    //A variable which will help in the menu-driven logic to store user's choice from 1,2,3,4 and 5
    int userChoice;

    cout << "\t\t\t\tWelcome to this 'Simple Ranking System!'\n\t\t\t\t=======================================\n\n";
    cout<<"~Made by: ALEENA KHAN\n";
    cout<<"~Roll#:CPE-2023-08\n";
    cout<<"~Build as a PBL(Project Based Learning) TASK of my 4TH SEMESTER Course, DSA(Data Structures and Algorithms) assigned by my Instructors.\n";    
    cout<< "~Language Used: 'C++ Programming Language.'\n";
    cout<< "~Its a terminal based project.\n";
    cout<<"----------------------------------------------------------------------\n\n";
    cout<<"\t\t\t\t\tIts a Menu-driven Program:\n\t\t\t\t\t==========================\n";
//The condition 'true' means its an infinite loop, it will run forever unless the program ends or the condition becomes 'false'
    while (true) {
        //Menu-driven logic
        cout << "\nChoose an option:\n";
        cout << "1: Add participant data\n";
        cout << "2: Sort the data\n";
        cout << "3: Display the results\n";
        cout << "4: Search for a participant's rank\n";
        cout << "5: Exit\n";
        cout << "Your choice: ";
        cin >> userChoice;

//switch-case
        switch (userChoice) {
            case 1:
                AddData(DataArray, count);
                break;//Break statement to prevent the below cases from executing
            case 2:
            //Firstly check if it can be sorted or not
                if (count == 0) {
                 cout << "There is no data to sort. Please add participant data first.\n";
                         }
                else if (count > 0)
                    ArrangeInDescendingOrder(DataArray, count);
                break;
            case 3:
                DisplayData(DataArray, count);
                break;
            case 4:
                SearchParticipant(DataArray, count);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
            //The default case runs if no above condition is true
                cout << "Invalid option. Please choose from 1 to 5.\n";
        }
    }

    return 0;
}

//AddData function to add new data of participant i.e: Name & Score 
void AddData(Participant DataArray[], int &count){
//passing count as 'alias' to make a imaginary variable in memory

    //A variable to store user opinion on how many participants data //he want to add
    int addCount;
    cout << "How many participants do you want to add? ";
    cin >> addCount;

    if (addCount <= 0) {
        cout << "Invalid number. Try again.\n";
        return;//Taking control back to caller
    }

//Condition to check if the count exceeds the size of array, that we set earlier was 100
    if (count + addCount > MAX_PARTICIPANTS) {
        //Displaying the counts left in array
        cout << "Cannot add that many participants. Max allowed: " << (MAX_PARTICIPANTS - count) << "\n";
        //Suppose,  100-95 = 5 counts left 
        return; 
    }
//if the above both checks fails that means we can add new participants easily
//for loop to add data 
    for (int i = 0; i < addCount; i++) {
        cout << "Enter name of participant " << (count + 1) << ": ";
        cin >> DataArray[count].name;
        cout << "Enter score of " << DataArray[count].name << ": ";
        cin >> DataArray[count].score;
        count++;
    }
    cout << "Data added successfully! Total participants: " << count << "\n";
}
//'ArrangeInDescendingOrder' function to sort data of participants in decreasing order which will inturn help us in ranking them 
void ArrangeInDescendingOrder(Participant DataArray[], int count) {
    
    //Here, I am using the built-in Quick sort function from the 'algorithm' library that I included at the start
    //It is called as 'Introsort' 
    // It is a hybrid of insertion sort, heap sort & quick sort
    //Here, the lambda comparator logic is used to sort them in descend order 
    sort(DataArray, DataArray + count, [](const Participant &a, const Participant &b) {
        return a.score > b.score;
    });
    
    cout << "Data sorted in descending order by score.\n";
}

//'DisplayData' function to display the Rankings of participants along with their names and scores
void DisplayData(const Participant DataArray[], int count) {
    //checking if data in array is empty
    if (count == 0) {
        cout << "No data to display. Please add participant data first.\n";
        return;//taking control back
    }
//if the above condition doesnt runs that means there is some data in array to display
    cout << "\nRankings:\n";
    //A for loop to display the data i.e: rank, name, and score of participant
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". " << DataArray[i].name << " - " << DataArray[i].score << "\n";
    }
    //We are assuming as the first element holds the largest score
    int topScore = DataArray[0].score;
    cout << "\nTop Scorer(s):\n";
    //Starting a loop just in case two participants have the same score 
    for (int i = 0; i < count && DataArray[i].score == topScore; i++) {
        cout << DataArray[i].name << " (" << DataArray[i].score << ")\n";
    }}
//'SearchParticipant' function works to search the rank of a particular participant on entering his name
void SearchParticipant(const Participant DataArray[], int count) {
    //A check to confirm if the array is empty
    if (count == 0) {
        cout << "No data available to search. Please add participant data first.\n";
        return;
    }
//A variable to store the name of participant as input from user of whose rank to search
    string searchName;
    cout << "Enter participant name to search: ";
    cin >> searchName;
//A boolean datatype to store the response as if we found the participant or not
//Initially it is set to 'false'
    bool found = false;
    //Starting a for loop on the array
    for (int i = 0; i < count; i++) {
        //runs when the participant we want to search is found 
        if (DataArray[i].name == searchName) {
            cout << searchName << " is ranked #" << (i + 1) << " with a score of " << DataArray[i].score << ".\n";
            found = true;// since we found it
            break;
        }
    }
    //runs only if the participant we want to search doesnot exist
    if (!found) {
        cout << "Participant named '" << searchName << "' not found.\n";
    }
}
