#ifndef _CLIENT_CODE_H_
#define _CLIENT_CODE_H_

#include <array>
#include <cassert>
#include <climits>

//template <int player = 0>
template <int player>
struct TicTacToeGameLogic {
    using State = std::array< std::array<int, 3> ,3>; // [3][3]; // = {{0,0,0}, {0,0,0}, {0,0,0}};
    using Score = std::array<int, 2>; // TODO: this should be declared in engine?

    static constexpr /*const*/ State initialState {{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }};

    static constexpr State next(const State& state) {
        State next = state;
        // TODO
        return next;
    }

    static constexpr const Score wl() noexcept;

    static constexpr const Score score(const State& state) noexcept {
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

    static constexpr bool gameOver(const State& state) noexcept {
        const Score s = score(state);
        return s[0] == INT_MAX || s[1] == INT_MAX;
    }

};

template <>
constexpr const std::array<int, 2> TicTacToeGameLogic<0>::wl() noexcept {
    return {INT_MAX, 0};
}

template <>
constexpr const std::array<int, 2> TicTacToeGameLogic<1>::wl() noexcept {
    return {0, INT_MAX};
}


#endif
