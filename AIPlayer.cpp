#include "AIPlayer.h"
#include <climits>
#include "Board.h"
#include <iostream>

AIPlayer::AIPlayer(char symbol) : Player(symbol) {
    opponent = (symbol == 'X') ? 'O' : 'X';
}

bool AIPlayer::makeMove(Board& board)  {
    int size = board.getSize();
    int bestScore = INT_MIN;
    int bestRow = -1;
    int bestCol = -1;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board.getCell(i, j) == ' ') {
                board.setCell(i, j, symbol);
                int score = minimax(board, false, 0, INT_MIN, INT_MAX);
                board.setCell(i, j, ' ');
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
      board.setCell(bestRow, bestCol, symbol);
      return true;
}

int AIPlayer::minimax(Board& board, bool isMaximizing, int depth, int alpha, int beta) {
    const int maxDepth = 3; 
    int size = board.getSize();

    if (board.checkWin(symbol)) return 10 - depth;
    if (board.checkWin(opponent)) return depth - 10;
    if (board.isDraw() || depth >= maxDepth) return 0;

    int bestScore = isMaximizing ? INT_MIN : INT_MAX;
    char current = isMaximizing ? symbol : opponent;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board.getCell(i, j) == ' ') {
                board.setCell(i, j, current);
                int score = minimax(board, !isMaximizing, depth + 1, alpha, beta);
                board.setCell(i, j, ' ');

                if (isMaximizing) {
                    bestScore = std::max(bestScore, score);
                    alpha = std::max(alpha, bestScore);
                }
                else {
                    bestScore = std::min(bestScore, score);
                    beta = std::min(beta, bestScore);
                }

                if (beta <= alpha) break;
            }
        }
    }

    return bestScore;
}
