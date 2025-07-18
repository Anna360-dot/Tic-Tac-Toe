#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include "Board.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Game.h"
    
int main()
{
   std::cout << "HELLO!\nWELCOME TO OUR TIC TAC TOE GAME!\n\n";

    int mode;
    std::cout << "Choose the mode:\n1. Human vs Human\n2. Human vs AI" << std::endl;
    std::cin >> mode;

    if (mode==1) {
        std::string name1, name2;

        std::cout << "Enter your name: ";
        std::cin >> name1;

        std::cout << "Enter your name: ";
        std::cin >> name2;

        std::cout << "Let's get started!\n\n";

        Game game(false);
        game.play();
    }
    else if (mode == 2) {
        std::string name;

        std::cout << "Enter your name: ";
        std::cin >> name;

        std::cout << "Let's get started!\n\n";

        Game game(true);
        game.play();
    }

    return 0;
}
