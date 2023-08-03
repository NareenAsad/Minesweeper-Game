#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void printBoard(char board[7][7]);
    void boardSetup();

protected:
    char board1[7][7]; // To be seen by the user
};
#endif // BOARD_H