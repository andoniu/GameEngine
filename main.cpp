#include "engine.hpp"
#include "clientCode.hpp"

#include <iostream>

// TODO: make this generic
int main(int /*argc*/, char* /*argv*/[]) {
    GameEngine<TicTacToeState, 2> ticTacToeGame;
    TicTacToeState state;
    auto score = ticTacToeGame.minimax(state, 199);
    std::cout << "result: " << score[0] << ":" << score[1] << std::endl;
    std::cout << "move: " << ticTacToeGame.getBestMove().x << ":" << ticTacToeGame.getBestMove().y << std::endl;
    // make one move at a time
    for (int i=0; i<8; i++) {
        state = state.next(ticTacToeGame.getBestMove());
        state.print();
        score = ticTacToeGame.minimax(state, 199);
        std::cout << "result " << i << ": " << score[0] << ":" << score[1]
            << " player: " << state.getCurrentPlayer() << std::endl;
        std::cout << "move " << i << ": " << ticTacToeGame.getBestMove().x << ":" << ticTacToeGame.getBestMove().y << std::endl;
    }
}
