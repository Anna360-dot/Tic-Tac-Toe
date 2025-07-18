#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board {
private:
    std::vector<std::vector<char>> board;
    int size;
public:
    Board();
    void createBoard();
    char getCell(int i, int j) const;
    char setCell(int i, int j, char player);
    int getSize() const;
    void setSize(int size1);
    bool isDraw() const;
    bool checkWin(char current) const;
};
#endif 