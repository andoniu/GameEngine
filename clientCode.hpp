#ifndef _CLIENT_CODE_H_
#define _CLIENT_CODE_H_

#include <array>
#include <cassert>
#include <climits>

template <int player>
struct TicTacToeGameLogic {
    using State = std::array< std::array<int, 3> ,3>; // [3][3]; // = {{0,0,0}, {0,0,0}, {0,0,0}};
    using Score = std::array<int, 2>; // TODO: this should be declared in engine?

    constexpr State next(const State& state) {
        State next = state;
        // TODO
        return next;
    }

    constexpr const Score wl() const noexcept;

    constexpr const Score score(const State& state) const noexcept {
        for(int i=0; i<3; i++){
            if (state[i][0] && state[i][0] == state[i][1] &&
                state[i][1] == state[i][2]) {
                    assert(state[i][0] == player);
                    return wl();
                }
            if (state[0][i] && state[0][i] == state[1][i] &&
                state[1][i] == state[2][i]) {
                    return wl();
                }
            if (state[0][0] && state[0][0] == state[1][1] &&
                state[1][1] == state[2][2]) {
                    return wl();
                }
        }
        if (state[2][0] && state[2][0] == state[1][1] &&
            state[1][1] == state[0][2]) {
                return wl();
        }
        return {0, 0};
    }

};

template <>
constexpr const std::array<int, 2> TicTacToeGameLogic<0>::wl() const noexcept {
    return {INT_MAX, 0};
}

template <>
constexpr const std::array<int, 2> TicTacToeGameLogic<1>::wl() const noexcept {
    return {0, INT_MAX};
}


#endif
