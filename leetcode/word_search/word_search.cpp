#include <iostream>
#include <vector>

using namespace std;

// Not the best solution possible, the initial loop I think it can be avoided
class Solution {
    bool used[210][210];

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exi(board, word, m, n, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool exi(vector<vector<char>>& board, string word, int m, int n, int i,
             int j, int at) {
        if (at == word.size()) return true;
        if (i >= m || i < 0) return false;
        if (j >= n || j < 0) return false;
        if (used[i][j]) return false;
        if (board[i][j] != word.at(at)) return false;

        used[i][j] = true;

        bool res = exi(board, word, m, n, i + 1, j, at + 1) ||  // up
                   exi(board, word, m, n, i - 1, j, at + 1) ||  // down
                   exi(board, word, m, n, i, j - 1, at + 1) ||  // left
                   exi(board, word, m, n, i, j + 1, at + 1);    // right

        used[i][j] = false;

        return res;
    }

    Solution() { memset(used, false, 210 * 210); };
};

int main() {
    vector<vector<char>> v;
    v.push_back(vector<char>{'A', 'B', 'C', 'E'});
    v.push_back(vector<char>{'S', 'F', 'C', 'S'});
    v.push_back(vector<char>{'A', 'D', 'E', 'E'});

    cout << Solution().exist(v, "AAB") << endl;

    return 0;
}
