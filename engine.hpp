#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include <climits> // max/min
#include <vector>
#include <functional>
#include <array>

#include <iostream>

namespace gamealgo {
    template <typename GameState, int nbPlayers, int player = 0>
    GameState minimax() {
    }
}

template <int numberOfPlayers>
class GameEngine {
//    State bestMove;

public:
    typedef std::array<int, numberOfPlayers> Score; // TODO: std::tuple maybe?

    template <typename GameState, int player = 0>
    constexpr GameState minimax(const GameState& state, unsigned int searchLevel) const noexcept {
        //std::cout << "minmax(" << searchLevel << ")" << std::endl;
        if (state.gameOver() || searchLevel == 0) {
            return state;
        }
        auto currentPlayer = state.getCurrentPlayer();
        int max = INT_MIN;
        Score maxScore {};
        for (auto nextState : state.moves()) {
            //auto nextState = state.next(move);
            GameState bestState = minimax<player+1>(nextState, searchLevel - 1);
            // pick the biggest score, regardless of other players
            if ( bestState.evaluate() > state.evaluate() ){
                
            }
            // TODO
            // if (score[currentPlayer] > max) {
            //     max = score[currentPlayer];
            //     // bestMove = move; // move-ctor
            //     maxScore = score;
            // }
        }
        return maxScore;
    }


    // const GameMove& getBestMove() const noexcept {
    //     return bestMove; 
    // }
};


template <int numberOfPlayers>
template <typename GameState>
constexpr GameState GameEngine<numberOfPlayers>::minimax<GameState, numberOfPlayers>(const GameState& state, unsigned int searchLevel) /*const noexcept*/ {
        return minimax<GameState, numberOfPlayers, 0>(state, searchLevel);
}


/////////
//
//#include <iostream>

int cnt = 0;

template <typename GameState>
struct GameEngine
{
    template <int=0> GameState minimax();
};

template <typename GameState>
template <int p>
GameState GameEngine<GameState>::minimax() {
    return minimax<p+1>();
}
template <>
template <typename X>
int GameEngine<int>::minimax<5>() {
    std::cout << "reached " << cnt << std::endl;
    if (++cnt == 20) return 0;
    return GameEngine<int>::minimax<0>();
}



int main() {
    GameEngine<int> x;
    x.minimax();
}
//
//
#endif
