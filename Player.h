#ifndef PLAYER_H
#define PLAYER_H
#include "Board.h"

class Player {
protected:
	char symbol;
public:
	Player(char mark) : symbol(mark){}
	virtual bool makeMove(Board& board)=0;
	virtual ~Player() {}
	char getSymbol()const { return symbol; }
};
#endif