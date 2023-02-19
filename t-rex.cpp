#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Function to set the console cursor position
void setCursorPosition(int x, int y) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

int main() {
    int score = 0;
    int delay = 100; // Delay in milliseconds
    int height = 10;
    int width = 40;
    int dinoPos = height - 1;
    int cactusPos = width - 1;
    bool gameover = false;

    // Clear the console screen
    system("cls");

    // Print the initial game board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == dinoPos && j == 0) {
                cout << "O";
            }
            else if (i == height - 1) {
                cout << "-";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Main game loop
    while (!gameover) {
        // Move the cactus
        cactusPos--;
        if (cactusPos < 0) {
            cactusPos = width - 1;
            score++;
        }

        // Check for collision
        if (cactusPos == 0 && dinoPos == height - 1) {
            gameover = true;
        }

        // Update the game board
        setCursorPosition(0, 0);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == dinoPos && j == 0) {
                    cout << "O";
                }
                else if (i == height - 1) {
                    cout << "-";
                }
                else if (i == height - 1 && j == cactusPos) {
                    cout << "X";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }

        // Wait for a short delay
        Sleep(delay);
        if (_kbhit()) {
            // Check if the user has pressed the space bar
            char key = _getch();
            if (key == ' ') {
                dinoPos = height - 2;
            }
        }

        // Move the dinosaur
        if (dinoPos < height - 1) {
            dinoPos++;
        }
    }

    // Print the final score
    cout << "Game over! Your score is " << score << "." << endl;

    return 0;
}
