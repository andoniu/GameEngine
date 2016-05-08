#include "engine.hpp"
#include "clientCode.hpp"

#include <iostream>

// TODO: make this generic
int main(int /*argc*/, char* /*argv*/[]) {
    GameEngine<TicTacToeState, TicTacToeMove> ticTacToeGame;
    TicTacToeState state;
    std::cout << "result: " << ticTacToeGame.minimax(state, 50) << std::endl;
    std::cout << "move: " << ticTacToeGame.getBestMove().x << ":" << ticTacToeGame.getBestMove().y << std::endl;
    // make one move at a time
    for (int i=0; i<8; i++) {
        state = state.next(ticTacToeGame.getBestMove());
        std::cout << "result " << i << ": " << ticTacToeGame.minimax(state, 20) << std::endl;
        std::cout << "move " << i << ": " << ticTacToeGame.getBestMove().x << ":" << ticTacToeGame.getBestMove().y << std::endl;
    }
}
