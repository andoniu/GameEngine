#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include <climits> // max/min
#include <vector>
#include <functional>
#include <array>

template <class GameState, typename GameMove, int numberOfPlayers>
class GameEngine {
    GameMove bestMove;

public:
    typedef std::array<int, numberOfPlayers> Score;


    Score minimax(const GameState& state, unsigned int searchLevel) {
        if (state.gameOver() || searchLevel == 0) {
            return state.evaluate();
        }
        auto currentPlayer = state.getCurrentPlayer();
        int max = INT_MIN;
        Score maxScore;
        for (auto move : state.moves()) {
            auto nextState = state.next(move);
            Score score = minimax(nextState, searchLevel - 1);
            // pick the biggest score, regardless of other players
            if (score[currentPlayer] > max) {
                max = score[currentPlayer];
                bestMove = move; // copy-ctor
                maxScore = score;
            }
        }
        return maxScore;
    }
    
    const GameMove& getBestMove() {
        return bestMove; 
    }
};

#endif
