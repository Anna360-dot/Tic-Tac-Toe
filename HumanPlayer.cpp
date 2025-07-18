#include "HumanPlayer.h"
#include "Board.h"
#include <iostream>

HumanPlayer::HumanPlayer(char symbol) : Player(symbol){}

bool HumanPlayer::makeMove(Board& board)  {
    int i, j;
    std::cout << "Enter your move:";
    std::cin >> i >> j;

    int size = board.getSize();

    if (i < 0 || j < 0 || i >= size || j >= size) {
        return false;
    }

    if (board.getCell(i, j) == ' ') {
        board.setCell(i, j, symbol);
        return true;
    }

    return false;
}





