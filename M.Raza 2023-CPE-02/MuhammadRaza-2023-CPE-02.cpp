#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
const int MAX_LENGTH = 100;

char grid[HEIGHT][WIDTH];
int snakeX[MAX_LENGTH];
int snakeY[MAX_LENGTH];
int snakeLength = 1;

int foodX, foodY;
bool gameOver = false;
bool started = false;
char direction = ' '; // Initially no direction
int score = 0;

// Hide cursor
void hideCursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &info);
}

// Initialize game
void setup() {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            grid[i][j] = ' ';

    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    grid[snakeY[0]][snakeX[0]] = 'O';

    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    grid[foodY][foodX] = '*';
}

// Draw the grid
void draw() {
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    for (int i = 0; i < WIDTH + 2; i++) cout << "#";
    cout << "\n";

    for (int i = 0; i < HEIGHT; i++) {
        cout << "#";
        for (int j = 0; j < WIDTH; j++) {
            cout << grid[i][j];
        }
        cout << "#\n";
    }

    for (int i = 0; i < WIDTH + 2; i++) cout << "#";
    cout << "\nScore: " << score << "\n";
    if (!started)
        cout << "Press W/A/S/D to start..." << endl;
}

// Get user input
void input() {
    if (_kbhit()) {
        char key = _getch();
        if ((key == 'w' || key == 'W') && direction != 'S') direction = 'W';
        else if ((key == 's' || key == 'S') && direction != 'W') direction = 'S';
        else if ((key == 'a' || key == 'A') && direction != 'D') direction = 'A';
        else if ((key == 'd' || key == 'D') && direction != 'A') direction = 'D';
        started = true;
    }
}

// Move the snake
void logic() {
    if (!started) return;

    int newX = snakeX[0];
    int newY = snakeY[0];

    if (direction == 'W') newY--;
    else if (direction == 'S') newY++;
    else if (direction == 'A') newX--;
    else if (direction == 'D') newX++;

    if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
        gameOver = true;
        return;
    }

    // Check self collision (linear search)
    for (int i = 1; i < snakeLength; i++) {
        if (snakeX[i] == newX && snakeY[i] == newY) {
            gameOver = true;
            return;
        }
    }

    for (int i = snakeLength; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    snakeX[0] = newX;
    snakeY[0] = newY;

    if (newX == foodX && newY == foodY) {
        snakeLength++;
        score += 10;
        do {
            foodX = rand() % WIDTH;
            foodY = rand() % HEIGHT;
        } while (grid[foodY][foodX] == 'O');
    }

    // Clear grid
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            grid[i][j] = ' ';

    grid[foodY][foodX] = '*';

    for (int i = 0; i < snakeLength; i++)
        grid[snakeY[i]][snakeX[i]] = 'O';
}

int main() {
    srand(time(0));
    hideCursor();   // Hide blinking cursor
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(120); // Control speed
    }

    cout << "\nGame Over!\nFinal Score: " << score << endl;
    system("pause");
    return 0;
}

