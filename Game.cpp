#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

Game::Game(bool vsAI) {
	char symbol1 = 'X';
	char symbol2 = 'O';

	if (vsAI) {
		player1 =new HumanPlayer(symbol1);
		player2 = new AIPlayer(symbol2);
	   
		char choice;
		
		do {
			std::cout << "Do you want to be X or O?";
			std::cin >> choice;
			choice = toupper(choice);
		} while (choice != 'X' && choice != 'O');

		symbol1 = choice;
		choice = (choice == symbol1) ? symbol2 : symbol1;
    }
	else {
		player1 = new HumanPlayer(symbol1);
		player2 = new HumanPlayer(symbol2);
	}
	currentPlayer = player1;
}

void Game::switchPlayer() {
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

static void clearScreen() {
	system("cls");
}

void Game::play() {
	int size;
	
	do {
		std::cout << "Enter board size :";
		std::cin >> size;
	} while (size < 3 || size > 5);

	board.setSize(size);
	
	while (true) {
		clearScreen();
		board.createBoard();
		
		while (!currentPlayer->makeMove(board)) {
			std::cout << "Invalid move. Try again!" << std::endl;;
			continue;
		}
		
		if (board.checkWin(currentPlayer->getSymbol())) {
			clearScreen();
			board.createBoard();
			std::cout << "Player " << currentPlayer->getSymbol() << " wins!" << std::endl;
			break;
		}

		if (board.isDraw()) {
			clearScreen();
			board.createBoard();
			std::cout << "It's a draw." << std::endl;
			break;
		}
		switchPlayer();
	}
}

Game::~Game() {
	delete player1;
	delete player2;
}