#include <iostream>
#include <string>
#include <limits>
#include "ATM.h"
#include "Account.h"
#include "Transaction.h"
#include "utils.h"

using namespace std;

// Function prototypes
void displayWelcomeScreen();
void displayMainMenu();
Account* authenticateUser(ATM& atm);
void handleBalanceInquiry(Account* account);
void handleDeposit(ATM& atm, Account* account);
void handleWithdrawal(ATM& atm, Account* account);
void handleTransactionHistory(Account* account);
void clearInputBuffer();
void pressEnterToContinue();

int main() {
    // Initialize ATM with sample accounts
    ATM atm;
    
    // Create and add sample accounts
    Account* acc1 = new Account("123456789", "1234", 1000.00);
    Account* acc2 = new Account("987654321", "4321", 500.00);
    atm.addAccount(acc1);
    atm.addAccount(acc2);

    // Display welcome screen
    displayWelcomeScreen();

    // Authenticate user
    Account* currentAccount = authenticateUser(atm);
    if (!currentAccount) {
     
        cout << "\033[1;32m----------------------------------------------------------------------------------------------\033[0m" << endl;
cout << "\033[1;93m                               TRANSCATION FAILED.Please try again later                                \033[0m" << endl;
cout << "\033[1;92m        Your Card has been Temporarily Blocked due to Multiple Incorrect PIN attempts                    \033[0m" << endl;
cout << "\033[1;92m                               Card Retained(Take your Card)                                 \033[0m" << endl;
cout << "\033[1;32m----------------------------------------------------------------------------------------------\033[0m" << endl;
cout << "\033[1;92m                                <<  Contact your BANK  >>                                 \033[0m" << endl;
cout << "\033[1;32m----------------------------------------------------------------------------------------------\033[0m" << endl;
        return 1;
    }

    // Main application loop
    bool running = true;
    while (running) {
        displayMainMenu();
        
        int choice;
        
               
cout << "\033[1;93m                               Enter your choice (1-5):                                  \033[0m" << endl;
 cout << "\033[1;37m==============================================================================================\033[0m" << endl;
        
        // Validate input
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            clearInputBuffer();
           
cout << "\033[1;35m()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()\033[0m" << endl;
cout << "\033[1;93m                               Invalid input. Please enter a number between 1 and 5                \033[0m" << endl;
cout << "\033[1;35m()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()\033[0m" << endl;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                handleBalanceInquiry(currentAccount);
                break;
            case 2:
                handleDeposit(atm, currentAccount);
                break;
            case 3:
                handleWithdrawal(atm, currentAccount);
                break;
            case 4:
                handleTransactionHistory(currentAccount);
                break;
            case 5:
                cout << "\033[1;35m$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\033[0m" << endl;
    cout << "\033[1;93m                             Thank you for using our ATM. Goodbye!                           \033[0m" << endl;
               cout << "\033[1;35m$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\033[0m" << endl;
                running = false;
                break;
        }

        if (running) {
            pressEnterToContinue();
        }
    }

    return 0;
}


void displayWelcomeScreen() {
<<<<<<< HEAD
    system("cls"); // For Windows to clear the terminal (use "clear" on Linux/Mac)
    cout << "==============================================================" << endl;
    cout << "||                                                          ||" << endl;
    cout << "||                 🌟  WELCOME TO  🌟                         ||" << endl;
    cout << "||                                                          ||" << endl;
    cout << "||             💳  BANK ATM MANAGEMENT SYSTEM  💳            ||" << endl;
    cout << "||                                                          ||" << endl;
    cout << "||               Powered by C++ and OOP 🧠                  ||" << endl;
    cout << "||                                                          ||" << endl;
    cout << "==============================================================" << endl << endl;
=======
    system("cls");  // For Windows to clear the terminal (use "clear" on Linux/Mac)
    
    // Stylish welcome message with colors and emojis
    cout << "\033[1;34m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m" << endl;
    cout << "\033[1;35m||                                                                                          ||\033[0m" << endl;
    cout << "\033[1;32m||                                        WELCOME TO THE                                    ||\033[0m" << endl;
    cout << "\033[1;36m||                                                                                          ||\033[0m" << endl;
    cout << "\033[1;33m||                                  BANK ATM MANAGEMENT SYSTEM                              ||\033[0m" << endl;
    cout << "\033[1;34m||                                                                                          ||\033[0m" << endl;
    cout << "\033[1;34m||                                                                                          ||\033[0m" << endl;
    cout << "\033[1;34m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m" << endl;

  // Optional - Add a brief animation or delay if desired
cout << "\033[1;34m----------------------------------------------------------------------------------------------\033[0m" << endl;
cout << "\033[1;93m                               Press Enter to start your session                             \033[0m" << endl;
    
    cin.get();  // Wait for user input
>>>>>>> 0d228b6a91dd6f8e36d926768b2f7c1bf4c5ad23
}


void displayMainMenu() {
    cout << "\033[1;36m                               ~~~~~~~ ATM MAIN MENU ~~~~~~~                                                   "<<endl;
    cout << "\033[1;37m==============================================================================================\033[0m" << endl;
    cout << "\033[1;36m  [1] Check Account Balance                                                                   \033[0m" << endl;
    cout << "\033[1;36m  [2] Deposit Funds                                                                           \033[0m" << endl;
    cout << "\033[1;36m  [3] Withdraw Funds                                                                          \033[0m" << endl;
    cout << "\033[1;36m  [4] View Transaction History                                                                \033[0m" << endl;
    cout << "\033[1;36m  [5] Exit                                                                                    \033[0m" << endl;
    cout << "\033[1;37m==============================================================================================\033[0m" << endl;
}

Account* authenticateUser(ATM& atm) {
    string accountNumber, pin;
    int attempts = 3;

    while (attempts > 0) {
      
cout << "\033[1;93m                             kindly enter your account number below                  \033[0m" << endl;
   cout << "\033[1;34m----------------------------------------------------------------------------------------------\033[0m" << endl;
cout << "> ";

        getline(cin, accountNumber);

        cout << "Enter your PIN: ";
        getline(cin, pin);

        Account* account = atm.findAccount(accountNumber);
        if (account && account->verifyPin(pin)) {
             cout << "\033[1;33m----------------------------Authentication successful. Welcome!-------------------------------\033[0m" << endl;
            return account;
        }

        attempts--;
        if (attempts > 0) {
            cout << "\nInvalid account number or PIN. " << attempts 
                 << " attempts remaining." << endl;
        }
    }

    return nullptr;
}

void handleBalanceInquiry(Account* account) {
    cout << "\nACCOUNT BALANCE" << endl;
    cout << "----------------" << endl;
    cout << "Account: " << utils::maskAccountNumber(account->getAccountNumber()) << endl;
    cout << "Available Balance: " << utils::formatCurrency(account->getBalance()) << endl;
}

void handleDeposit(ATM& atm, Account* account) {
    cout << "\nDEPOSIT FUNDS" << endl;
    cout << "--------------" << endl;
    cout << "Current Balance: " << utils::formatCurrency(account->getBalance()) << endl;

    double amount;
    cout << "\nEnter amount to deposit (max $10,000): $";
    
    while (!(cin >> amount) || !utils::isValidAmount(amount)) {
        clearInputBuffer();
        cout << "Invalid amount. Please enter a positive amount up to $10,000: $";
    }
    clearInputBuffer();

    // Confirm deposit
    cout << "\nYou are about to deposit " << utils::formatCurrency(amount) << endl;
    cout << "Confirm? (Y/N): ";
    char confirm;
    cin >> confirm;
    clearInputBuffer();

    if (toupper(confirm) == 'Y') {
        account->updateBalance(amount);
        account->addTransaction(new Transaction("Deposit", amount));
        atm.enqueueDeposit(account);
        
          cout << "\033[1;34m----------------------------------------Deposit successful!----------------------------------------------\033[0m" << endl;
        cout << "New Balance: " << utils::formatCurrency(account->getBalance()) << endl;
    } else {
        cout << "Deposit canceled." << endl;
    }
}

void handleWithdrawal(ATM& atm, Account* account) {
    cout << "\nWITHDRAW FUNDS" << endl;
    cout << "---------------" << endl;
    cout << "Current Balance: " << utils::formatCurrency(account->getBalance()) << endl;

    double amount;
    cout << "\nEnter amount to withdraw (max $10,000): $";
    
    while (!(cin >> amount) || !utils::isValidAmount(amount)) {
        clearInputBuffer();
        cout << "Invalid amount. Please enter a positive amount up to $10,000: $";
    }
    clearInputBuffer();

    if (amount > account->getBalance()) {
        cout << "\nInsufficient funds:( Your current balance is " 
             << utils::formatCurrency(account->getBalance()) << endl;
        return;
    }

    // Confirm withdrawal
    cout << "\nYou are about to withdraw " << utils::formatCurrency(amount) << endl;
    cout << "Confirm? (Y/N): ";
    char confirm;
    cin >> confirm;
    clearInputBuffer();

    if (toupper(confirm) == 'Y') {
        account->updateBalance(-amount);
        account->addTransaction(new Transaction("Withdrawal", amount));
        atm.enqueueWithdrawal(account);
        
         cout << "\033[1;34m----------------------------------------Withdrawal successful!--------------------------------------------\033[0m" << endl;
        cout << "Please take your cash:)" << endl;
        cout << "New Balance: " << utils::formatCurrency(account->getBalance()) << endl;
    } else {
        cout << "Withdrawal canceled:(" << endl;
    }
}

void handleTransactionHistory(Account* account) {
    account->displayTransactionHistory();
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pressEnterToContinue() {
    cout << "\nPress Enter to continue...";
    clearInputBuffer();
    cin.get();
}