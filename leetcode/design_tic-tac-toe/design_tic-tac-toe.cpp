#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

class TicTacToe {
   public:
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<int> diag;
    vector<int> antidiag;
    bool done;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<vector<int>>(2, vector<int>(n, n));
        cols = vector<vector<int>>(2, vector<int>(n, n));
        diag = vector<int>(2, n);
        antidiag = vector<int>(2, n);
        done = false;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (done) return 0;

        if (rows[player - 1][row]-- <= 1) return player;
        if (cols[player - 1][col]-- <= 1) return player;

        if (row == col && diag[player - 1]-- <= 1) return player;
        if (int(rows[player - 1].size()) - row - 1 == col &&
            antidiag[player - 1]-- <= 1)
            return player;

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TicTacToe *ticTacToe = new TicTacToe(3);

    // Assume that player 1 is "X" and player 2 is "O" in the board.
    if (ticTacToe->move(0, 0, 1) != 0) throw std::runtime_error("invalid 1");
    if (ticTacToe->move(0, 2, 2) != 0) throw std::runtime_error("invalid 2");
    if (ticTacToe->move(2, 2, 1) != 0) throw std::runtime_error("invalid 3");
    if (ticTacToe->move(1, 1, 2) != 0) throw std::runtime_error("invalid 4");
    if (ticTacToe->move(2, 0, 1) != 0) throw std::runtime_error("invalid 5");
    if (ticTacToe->move(1, 0, 2) != 0) throw std::runtime_error("invalid 6");
    if (ticTacToe->move(2, 1, 1) != 1) throw std::runtime_error("invalid 7");

    return 0;
}
