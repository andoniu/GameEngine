#include <iostream>

int cnt = 0;

template <int player=0>
struct GameEngine
{
    template <typename GameState> GameState minimax();
};

template <int p>
template <typename GameState>
GameState GameEngine<p>::minimax<GameState>() {
    return GameEngine<p+1>::minimax<GameState>();
}
template <>
template <typename GameState>
GameState GameEngine<5>::minimax() {
    std::cout << "reached " << cnt << std::endl;
    if (++cnt == 20) return 0;
    return GameEngine<0>::minimax<GameState>();
}



int main() {
    GameEngine<0> x;
    x.minimax<int>();
}
