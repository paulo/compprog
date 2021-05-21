#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, bool> r;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (r[board[i][j]]) {
                    return false;
                } else {
                    r[board[i][j]] = true;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_map<char, bool> c;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (c[board[j][i]]) {
                    return false;
                } else {
                    c[board[j][i]] = true;
                }
            }
        }

        for (int k = 0; k < 3; k++) {  // tracks square blocks
            for (int z = 0; z < 3; z++) {
                unordered_map<char, bool> m;
                for (int i = k * 3; i < (k + 1) * 3; i++) {
                    for (int j = z * 3; j < (z + 1) * 3; j++) {
                        if (board[i][j] == '.') continue;

                        if (m[board[i][j]])
                            return false;
                        else
                            m[board[i][j]] = true;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> board = {
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}};

    // vector<vector<char>> board = {
    // {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
    // {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    // {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    // {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    // {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    // {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    // {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    // {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    // {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << Solution().isValidSudoku(board) << endl;

    return 0;
}

