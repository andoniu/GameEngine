#include "engine.hpp"

#include <vector>
#include <array>
#include <iostream> // for debug

/*
 * This file should be replaced by the game logic of
 * whatever game you need to implement
 
 Need to define:
 Move, State
 */

// struct TicTacToeMove
// {
//     int x;
//     int y;
// };

class TicTacToeState
{
    //using Score = GameEngine<TicTacToeMove, 2>::Score;
    using Score = std::tuple<int,int>;
    int table[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    enum PlayerNumber {
        FIRST = 0,
        SECOND = 1
    };
    //unsigned int currentPlayer = 0;
    PlayerNumber currentPlayer = PlayerNumber::FIRST;
    Score score = {0,0};

    constexpr const Score wl() const noexcept {
        return  (currentPlayer == 1) ? Score({INT_MAX,INT_MIN}) : Score({INT_MIN,INT_MAX});
    }

public:
    unsigned int getCurrentPlayer() const noexcept {
        return currentPlayer;
    }
    
    // return all moves from this state
    std::vector<TicTacToeState> moves() const noexcept {
        std::vector<TicTacToeState> ret;
        ret.reserve(10);
        for(int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (table[i][j] == 0) {
                    ret.push_back(next(i,j));
                }
            }
        }
        return ret;
    }

    /*constexpr*/ bool gameOver() const noexcept {
        return std::get<0>(score) || std::get<1>(score);
    }

    void computeScore() noexcept {
        for(int i=0; i<3; i++){
            if (table[i][0] && table[i][0] == table[i][1] &&
                table[i][1] == table[i][2]) {
                    score = wl();
                    return;
                }
            if (table[0][i] && table[0][i] == table[1][i] &&
                table[1][i] == table[2][i]) {
                    score = wl();
                    return;
                }
            if (table[0][0] && table[0][0] == table[1][1] &&
                table[1][1] == table[2][2]) {
                    score = wl();
                    return;
                }
            if (table[2][0] && table[2][0] == table[1][1] &&
                table[1][1] == table[0][2]) {
                    score = wl();
                    return;
                }
        }
        
        score = {0,0};
    }

    // returns how good is the current position for the current player compared to others
    // bigger is better
    constexpr Score evaluate() const noexcept {
        return score;
    }

    TicTacToeState next(int x, int y) const noexcept {
        TicTacToeState nextState = *this;
        nextState.table[x][y] = currentPlayer+1;
        nextState.currentPlayer = currentPlayer == PlayerNumber::FIRST ?
            PlayerNumber::SECOND : PlayerNumber::FIRST;
        nextState.computeScore(); 
        return std::move(nextState);
    }
    
    // for debug
    void print() {
        for (int i=0; i<3; i++)
        {
            std::cout << table[i][0] << table[i][1] << table[i][2] << std::endl;
        }
        std::cout << "player: " << currentPlayer << " score: " << std::get<0>(score) << ":" << std::get<1>(score) << std::endl; 
    }
};
