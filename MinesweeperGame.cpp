#include "MinesweeperGame.h"
#include <iostream>
using namespace std;

MinesweeperGame::MinesweeperGame() : Board(), Mines() {}

void MinesweeperGame::start() {
    cout << "THE GOAL: Find the empty squares and avoid the mines." << endl << endl;
    cout << "THE RULES IN MINESWEEPER ARE SIMPLE:" << endl << endl;
    cout << "1. Uncover a mine, and the game ends." << endl;
    cout << "2. Uncover a number, and it tells you how many mines lay hidden in the eight surrounding squares." << endl;
    cout << "3. Use the information gathered from the number to unravel the position of mine" << endl;
    cout << endl << endl << "NOTE: You have to enter the position of numbers (NOT MINES)" << endl << endl << endl;

    cout << "LET'S START THE GAME..." << endl << "This is your board: " << endl;
    printBoard(board1);

    setMinesAndNumbers();

    // Play the game
    for (;;) {
        int x, y;
        getInput(&x, &y);

        board1[x][y] = board[x][y];
        printBoard(board1);

        if (board1[x][y] == '*') {
            cout << "THE MINE BLASTED..." << endl << "YOU LOST THE GAME..." << endl << "BETTER LUCK NEXT TIME...";
            return;
        }

        int count1 = 0, count2 = 0;
        for (int i = 1; i < 6; i++) {
            for (int j = 1; j < 6; j++) {
                if (board1[i][j] == '#') {
                    count1++;
                }
                if (board[i][j] == '*') {
                    count2++;
                }
            }
        }

        cout << endl << count2 << " mines left out of remaining " << count1 << " positions" << endl << endl;

        if (count1 == count2) {
            cout << "CONGRATS....." << endl << "YOU FOUND ALL THE MINES...." << endl << "YOU WON THE GAME....";
            return;
        }
    }
}

void MinesweeperGame::getInput(int* x, int* y) {
    bool isValidPosition = false;

    while (!isValidPosition) {
        cout << "Enter the row position: ";
        cin >> *x;
        cout << "Enter the column position: ";
        cin >> *y;
        isValidPosition = isValidInput(*x, *y) && board1[*x][*y] == '#';

        if (!isValidPosition) {
            cout << endl << "INVALID POSITION or ALREADY ENTERED.... TRY DIFFERENT ONE......" << endl;
        }
    }
    cout << endl;
}

bool MinesweeperGame::isValidInput(int x, int y) {
    return (x >= 1 && x <= 5 && y >= 1 && y <= 5);
}