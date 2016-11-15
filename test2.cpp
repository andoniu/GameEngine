#include <tuple>
#include <array>

#include <iostream>

// minimax algo
template <typename GameState, int numberOfPlayers, int maxDepth, int moveNumber,
    typename std::enable_if_t<maxDepth*numberOfPlayers == moveNumber>* = nullptr>
constexpr std::array<int, numberOfPlayers> minimax(const GameState& /*fromState*/) {
    std::cout << "limit reached..." << std::endl;
    return std::array<int, numberOfPlayers> {}; // TODO: compute here the score comparing to the other players
}

template <typename GameState, int numberOfPlayers, int maxDepth, int moveNumber,
    typename std::enable_if_t<(maxDepth*numberOfPlayers > moveNumber)>* = nullptr>
constexpr std::array<int, numberOfPlayers> minimax(const GameState& fromState) {
    constexpr int playerNumber = moveNumber % numberOfPlayers;
    std::cout << "player: " << playerNumber << " move number: " << moveNumber << std::endl;
    std::array<int, numberOfPlayers> bestScoreSoFar = {0}; // any score would be better than this
    for (GameState nextState : fromState.getAllStates()) {
         auto score = minimax<GameState, numberOfPlayers, maxDepth, moveNumber+1>(nextState);
         if (score[playerNumber] > bestScoreSoFar[playerNumber]) {
             bestScoreSoFar = score;
         }
    }
    return bestScoreSoFar;
}

int main() {
    struct TicTacToeState {
        int table[9];
        std::array<TicTacToeState, 3> getAllStates() const {
            return std::array<TicTacToeState, 3> {
               *this, *this, *this
            };
        }
    };
    TicTacToeState initialState = {0};
    minimax<TicTacToeState,3,7,0>(initialState);
}
