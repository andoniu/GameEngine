#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include <climits> // max/min
#include <vector>

template <class GameState, typename GameMove>
class GameEngine {
//    GameState state;
    GameMove bestMove; // TODO
public:

    int minimax(const GameState& state, unsigned int searchLevel) {
        if (state.gameOver() || searchLevel == 0)
            return state.evaluate();
        auto maxScore = INT_MIN;
        for (auto move : state.moves()) {
            auto nextState = state.next(move);
            auto score = minimax(nextState, searchLevel - 1);
            if (score > maxScore) {
                maxScore = score;
                bestMove = move; // copy-ctor
            }
        }
        return maxScore;
    }
    
    const GameMove& getBestMove() {
        return bestMove; 
    }
};

#endif
