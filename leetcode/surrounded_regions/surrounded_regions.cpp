#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool visited[210][210];

   public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size()) return;
        if (j < 0 || j >= board[i].size()) return;
        if (board[i][j] != 'O') return;
        if (visited[i][j]) return;

        visited[i][j] = true;

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;

        memset(visited, false, 210 * 210 * sizeof(bool));

        for (int i = 0; i < board.size(); i++) {
            dfs(board, i, 0);
            dfs(board, i, board[i].size() - 1);
        }

        for (int i = 0; i < board[0].size(); i++) {
            dfs(board, 0, i);
            dfs(board, board.size() - 1, i);
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //[["O","O"],["O","O"]]

    // vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
    // {'X', 'O', 'O', 'X'},
    // {'X', 'X', 'O', 'X'},
    // {'X', 'O', 'X', 'X'}};

    vector<vector<char>> board = {{'O', 'O'}, {'O', 'O'}};

    Solution().solve(board);

    for (auto x : board) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }

    return 0;
}
