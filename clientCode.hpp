#include "engine.hpp"

#include <vector>
#include <array>

/*
 * This file should be replaced by the game logic of
 * whatever game you need to implement
 
 Need to define:
 Move, State
 */

struct TicTacToeMove
{
    int x;
    int y;
};

class TicTacToeState
{
    using Score = GameEngine<TicTacToeState, TicTacToeMove, 2>::Score;
    int table[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    unsigned int currentPlayer = 0;
public:

    unsigned int getCurrentPlayer() const {
        return currentPlayer;
    }
    
    // return all moves from this state
    std::vector<TicTacToeMove> moves() const {
        std::vector<TicTacToeMove> ret;
        ret.reserve(10);
        for(int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (table[i][j] == 0) {
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }

    bool gameOver() const {
        for (int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if (table[i][j] == 0) return false;
        }
        for(int i=0; i<3; i++){
            if (table[i][0] == table[i][1] &&
                table[i][1] == table[i][2])
                return true;
            if (table[0][i] == table[1][i] &&
                table[1][i] == table[2][i])
                return true;
            if (table[0][0] == table[1][1] &&
                table[1][1] == table[2][2])
                return true;
            if (table[2][0] == table[1][1] &&
                table[1][1] == table[0][2])
                return true;
        }
        
        return false;
    }

    // returns how good is the current position for the current player compared to others
    // bigger is better
    Score evaluate() const {
        constexpr Score win = {1,-1};
        constexpr Score loss = {-1,1};
        if (gameOver()) {
            if (currentPlayer == 0)
                return win;
            else
                return loss;
        }
        return Score{{0,0}}; // don't know
    }

    TicTacToeState next(const TicTacToeMove& move) const {
        TicTacToeState nextState = *this;
        auto nextPlayer = (currentPlayer + 1) % 2;
        nextState.table[move.x][move.y] = nextPlayer+1;
        nextState.currentPlayer = nextPlayer;
        return nextState; // TODO: move ctor here maybe?
    }
};
