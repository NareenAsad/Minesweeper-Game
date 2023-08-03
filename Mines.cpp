#include "Mines.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Mines::Mines() {
    setMinesAndNumbers();
}

void Mines::setMinesAndNumbers() {
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            board[i][j] = '0';
        }
    }

    srand(static_cast<unsigned int>(time(0))); // Explicitly cast time(0) to unsigned int
    for (int k = 0; k < 6; k++) {
        int x = (rand() % 5) + 1;
        int y = (rand() % 5) + 1;
        if (board[x][y] == '*') {
            continue;
        }
        else {
            board[x][y] = '*';
            for (int i = x - 1; i < x + 2; i++) {
                for (int j = y - 1; j < y + 2; j++) {
                    if (board[i][j] == '*')
                        continue;
                    else {
                        int temp = static_cast<int>(board[i][j]) + 1; // Use static_cast for type conversion
                        board[i][j] = static_cast<char>(temp); // Use static_cast for type conversion
                    }
                }
            }
        }
    }
}