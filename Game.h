#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

class Game {
private:
	Player* player1;
	Player* player2;
	Player* currentPlayer;
	Board board;
	char symbol1;
	char symbol2;
public:
	Game(bool vsAI);
	~Game();
	void play();
	void switchPlayer();
};
#endif