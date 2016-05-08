#include <vector>

struct TicTacToeMove
{
    int x;
    int y;
};

class TicTacToeState
{
    int table[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    enum PlayerColor {
        BLACK = 1,
        WHITE = 2
    };
    PlayerColor color = WHITE;
public:
    // return all moves from this state
    std::vector<TicTacToeMove> moves() const {
        std::vector<TicTacToeMove> ret;
        ret.reserve(10);
        for(int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (table[i][j] == 0) {
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }

    bool gameOver() const {
        for (int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if (table[i][j] == 0) return false;
        }
        for(int i=0; i<3; i++){
            if (table[i][0] == table[i][1] &&
                table[i][1] == table[i][2])
                return true;
            if (table[0][i] == table[1][i] &&
                table[1][i] == table[2][i])
                return true;
            if (table[0][0] == table[1][1] &&
                table[1][1] == table[2][2])
                return true;
            if (table[2][0] == table[1][1] &&
                table[1][1] == table[0][2])
                return true;
        }
        
        return false;
    }

    // returns how good is the current position for the current player compared to others
    // bigger is better
    int evaluate() const {
        if (gameOver()) return -1; // game was ended, so we lost the game
        return 0; // don't know
    }

    TicTacToeState next(const TicTacToeMove& move) const {
        TicTacToeState nextState = *this;
        PlayerColor nextPlayerColor = color == WHITE ? BLACK : WHITE;
        nextState.table[move.x][move.y] = nextPlayerColor;
        nextState.color = nextPlayerColor;
        return nextState; // TODO: move ctor here maybe?
    }
};