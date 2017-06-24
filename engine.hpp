#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#include <tuple>
#include <array>
#include <vector>

#include <iostream>
#include <cassert>
#include <climits>

// TODO: make this as a concept. when it is defined

// minimax algo
template <typename GameLogic, int numberOfPlayers, int maxDepth, int moveNumber,
    typename std::enable_if_t<maxDepth*numberOfPlayers == moveNumber>* = nullptr>
constexpr std::array<int, numberOfPlayers> minimax(const typename GameLogic::State& fromState) {
    std::cout << "limit reached..." << std::endl;
    return fromState.score();
}

template <typename GameLogic, int numberOfPlayers, int maxDepth, int moveNumber,
    typename std::enable_if_t<(maxDepth*numberOfPlayers > moveNumber)>* = nullptr>
constexpr std::array<int, numberOfPlayers> minimax(const typename GameLogic::State& fromState) {
    constexpr int playerNumber = moveNumber % numberOfPlayers;
    //std::cout << "player: " << playerNumber << " move number: " << moveNumber << std::endl;
    std::array<int, numberOfPlayers> bestScoreSoFar = {0}; // any score would be better than this
    // for (const auto& nextMove : fromState.getAllPossibleMoves()) {
    //     auto nextState = fromState.apply(nextMove);
    //     auto score = nextState.evaluate();
    //     if (!GameLogic::gameOver(score)) {
    //         score = minimax<GameLogic, numberOfPlayers, maxDepth, moveNumber+1>(nextState);
    //     }
    //     else {
    //         std::cout << "GameOver!\n";
    //         //fromState.print();
    //         //nextState.print();
    //     }
    //     if (score[playerNumber] > bestScoreSoFar[playerNumber]) {
    //         bestScoreSoFar = score;
    //         nextState.print();
    //     }
    // }
    return bestScoreSoFar;
}

#endif
