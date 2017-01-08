

int main() {
    struct TicTacToeState {
        int currentPlayer = 2; // so 1 should be first player
        int table[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
        #if 0
        std::vector<TicTacToeState> getAllStates() const {
            std::vector<TicTacToeState> ret;
            int nextPlayer = currentPlayer == 1 ? 2 : 1;
            for (int i=0; i<3; i++)
            for (int j=0; j<3; j++) {
                if (table[i][j] == 0) {
                    TicTacToeState nextState = *this;
                    nextState.currentPlayer = nextPlayer;
                    nextState.table[i][j] = nextPlayer;
                    ret.push_back(nextState);
                }
            }
            return ret;
        }
        #endif
        using Move = std::tuple<int, int>; // x,y
        std::vector<Move> getAllPossibleMoves() const noexcept {
            std::vector<Move> result;
            for (int i=0; i<3; i++)
            for (int j=0; j<3; j++) {
                if (table[i][j] == 0) {
                    result.push_back(std::make_tuple(i, j));
                }
            }
            return result;
        }
        constexpr TicTacToeState apply(const Move& move) const noexcept {
            // TODO: how many ctors are beeing called here?
            TicTacToeState nextState = *this;
            int nextPlayer = (currentPlayer == 1) ? 2 : 1;
            nextState.currentPlayer = nextPlayer;
            nextState.table[std::get<0>(move)][std::get<1>(move)] = nextPlayer;
            return nextState;
      }
        constexpr const std::array<int, 2> wl() const noexcept {
           if (currentPlayer == 1) {
               return {INT_MAX,INT_MIN};
           } else {
               return {INT_MIN,INT_MAX};
           }
        }
        constexpr std::array<int, 2> evaluate() const noexcept {
            for(int i=0; i<3; i++){
                if (table[i][0] && table[i][0] == table[i][1] &&
                    table[i][1] == table[i][2]) {
                        assert(table[i][0] == currentPlayer);
                        return wl();
                    }
                if (table[0][i] && table[0][i] == table[1][i] &&
                    table[1][i] == table[2][i]) {
                        return wl();
                    }
                if (table[0][0] && table[0][0] == table[1][1] &&
                    table[1][1] == table[2][2]) {
                        return wl();
                    }
            }
            if (table[2][0] && table[2][0] == table[1][1] &&
                table[1][1] == table[0][2]) {
                    return wl();
            }
            return {0, 0};
        }
        static constexpr bool gameOver(const std::array<int, 2>& score) noexcept {
            if (score[0] || score[1]) return true;
            return false;
        }
        // for debug
        void print() const noexcept {
            constexpr char letter[3] = {
                ' ','X','0'
            };
            for (int i=0; i<3; i++)
            {
                if (i == 1 || i == 2) std::cout << "-+-+-\n";
                std::cout << letter[table[i][0]] << "|" << letter[table[i][1]] << "|" << letter[table[i][2]] << "\n";
            }
            auto score = evaluate();
            std::cout << "\t\tplayer: " << currentPlayer << " score: " << score[0] << ":" << score[1] << "\n"; 
        }
    };



    TicTacToeState initialState;
    minimax<TicTacToeState,2,19,0>(initialState);
}
