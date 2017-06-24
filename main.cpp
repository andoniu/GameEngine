#include "engine.hpp"
#include "clientCode.hpp"

#include <iostream>

// TODO: make this generic
int main(int /*argc*/, char* /*argv*/[]) {
    minimax<TicTacToeGameLogic,2,19,0>(TicTacToeGameLogic<0>::initialState);
}
