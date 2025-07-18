#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(char symbol);
    bool makeMove(Board& board) override;
};
#endif