#include "engine.hpp"
#include "clientCode.hpp"

#include <iostream>

// TODO: make this generic
int main(int /*argc*/, char* /*argv*/[]) {
    TicTacToeGameLogic::State initial;
    minimax<TicTacToeGameLogic,2,19,0>(initial);
}
