# Transaction Management System in C++
## Overview
This is a simple C++ project to manage basic user transactions. It allows users to deposit and withdraw money, view transaction history, undo the last transaction, and check their current balance.

## Features
- **Deposit**: Add funds to the account.
- **Withdraw**: Remove funds from the account if sufficient balance exists.
- **Show History**: View all past transactions.
- **Undo Last Transaction**: Revert the last deposit or withdrawal.
- **Show Balance**: Display the current balance.

## Technologies Used
- C++ Programming Language
- Standard Template Library (STL): `vector`, `pair`
- Console Input/Output

## Class Structure
### TransactionSystem
- **balance**: Stores the current balance.
- **history**: Stores the list of transactions (type and amount).
- **Methods**:
- deposit(double amount)
- withdraw(double amount)
- showHistory()
- undoLast()
- showBalance()
  
## Sample Menu
1. Deposit
2. Withdraw
3. Show History
4. Undo Last
5. Show Balance
0. Exit

## Future Improvements
- Add file saving and loading of transaction history
- Support for multiple users with login system

## Author
Esha Aslam
