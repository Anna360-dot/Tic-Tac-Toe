#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "Player.h"

class AIPlayer : public Player {
private:
    int minimax( Board& board, bool isMaximizing, int depth, int alpha, int beta );
    char opponent;
public:
    AIPlayer(char symbol);
    bool makeMove( Board& board ) override; 
};
#endif