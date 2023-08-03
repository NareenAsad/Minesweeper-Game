#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H
#include "Board.h"
#include "Mines.h"

class MinesweeperGame : public Board, public Mines {
public:
    MinesweeperGame();
    void start();

private:
    void getInput(int* x, int* y);
    bool isValidInput(int x, int y);
};
#endif // MINESWEEPERGAME_H