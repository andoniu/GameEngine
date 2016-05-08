#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include <climits> // max/min
#include <vector>
#include <functional>



template <class GameState, typename GameMove, int numberOfPlayers = 2>
class GameEngine {
//    GameState state;
    GameMove bestMove; // TODO
    
    typedef int Score [numberOfPlayers];
    unsigned int currentPlayer = 0;
public:

    GameEngine(std::function<std::vector<GameMove>()> moves) {
        moves();
    }

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
