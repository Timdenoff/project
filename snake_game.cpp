#include <iostream>
#include <conio.h>  // For _getch()

using namespace std;

// Game variables and constants
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

// Function to initialize the game settings
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;  // Starting position of the snake
    y = height / 2;
    fruitX = rand() % width;  // Random position for the fruit
    fruitY = rand() % height;
    score = 0;
}

// Function to draw the game screen
void Draw() {
    system("cls");  // Clear the screen
    for (int i = 0; i < width + 2; i++)
        cout << "#";  // Top border
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";  // Left border
            if (i == y && j == x)
                cout << "O";  // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "F";  // Fruit
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        print = true;
                        cout << "o";  // Snake body
                    }
                }
                if (!print)
                    cout << " ";  // Empty space
            }
            if (j == width - 1)
                cout << "#";  // Right border
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";  // Bottom border
    cout << endl;
    cout << "Score: " << score << endl;  // Display the score
}

// Function to handle user input
void Input() {
    switch (_getch()) {
    case 'a':
        if (dir != RIGHT) dir = LEFT;
        break;
    case 'd':
        if (dir != LEFT) dir = RIGHT;
        break;
    case 'w':
        if (dir != DOWN) dir = UP;
        break;
    case 's':
        if (dir != UP) dir = DOWN;
        break;
    case 'x':
        gameOver = true;
        break;
    }
}

// Function to update the game logic
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    // Check for boundary collision and wrap around
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // Check for collision with itself
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Check if fruit is eaten
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

// Main function to run the game loop
int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
