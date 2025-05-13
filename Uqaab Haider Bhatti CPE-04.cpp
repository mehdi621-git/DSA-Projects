#include <iostream>
#include <limits> 
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char currentPlayer = 'X';

void printBoard() {
    cout << "\nCurrent Board:\n";
    for(int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if(i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

bool checkWin() {
   
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
   
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

void makeMove() {
    int move;
    while(true) {
        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> move;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        
        if(move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
            break;
        }
        cout << "Invalid move! Try again.\n";
    }
}

int main() {
    cout << "Tic-Tac-Toe Game!\n";
    cout << "Player 1: X\nPlayer 2: O\n";
    cout << "Enter numbers 1-9 to make your move\n";
    
    while(true) {
        printBoard();
        makeMove();
        
        if(checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if(checkDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
