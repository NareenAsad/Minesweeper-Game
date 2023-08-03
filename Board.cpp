#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    boardSetup();
}

void Board::printBoard(char board[7][7]) {
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Board::boardSetup() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            board1[i][j] = '#';
        }
    }
}