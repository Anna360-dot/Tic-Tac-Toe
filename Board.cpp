#include <vector>
#include <iostream>
#include "Board.h"

Board::Board() {
    setSize(size);
}

void Board::setSize(int size1) {
    size = size1;
    board.resize(size, std::vector<char>(size, ' '));
}

void Board::createBoard() {
    int size = board.size();
    std:: string row = "+";

    for (int i = 0; i < size; ++i) {
        row += "---+";
    }

    for (int i = 0; i < size; ++i) {
        std::cout << row << std::endl;
        std::cout << '|';

        for (int j = 0; j < size; ++j) {
            std::cout <<' '<< board[i][j] << ' ' << '|';
        }
        std::cout << std::endl;
    }
   std::cout << row << std::endl;
}

char Board::getCell(int i, int j) const {
    return board[i][j];
}

char Board::setCell(int i, int j, char player) {
    board[i][j] = player;
    return board[i][j];
}

int Board::getSize() const {
    return size;
}

bool Board::isDraw() const {
    int size = getSize();
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (getCell(i, j) == ' ')
                return false;

    return true;
}

bool Board::checkWin(char current) const {
    int size = getSize();
    int diag1 = 0;
    int diag2 = 0;

    for (int i = 0; i < size; ++i) {
        int row = 0;
        int col = 0;
       
        for (int j = 0; j < size; ++j) {
            if (getCell(i, j) == current)
                row++;
            if (getCell(j, i) == current)
                col++;
        }

        if(row == size||col==size)   return true;
    
        if (getCell(i, i) == current)  diag1++;
               
        if (getCell(size - 1 - i, i) == current) diag2++;
       
    }

        if (diag1 == size||diag2==size)  return true; 

        return false;
}