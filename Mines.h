#ifndef MINES_H
#define MINES_H

class Mines {
public:
    Mines();
    void setMinesAndNumbers();

protected:
    char board[7][7]; // Backend board
};
#endif // MINES_H