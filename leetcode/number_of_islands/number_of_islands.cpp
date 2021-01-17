#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool visited[302][302];

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), c = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) continue;

                if (grid[i][j] == '1') {
                    c++;
                    dfs(grid, i, j, n, m);
                } else {
                    visited[i][j] = true;
                }
            }
        }

        return c;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (visited[i][j]) return;
        visited[i][j] = true;
        if (grid[i][j] != '1') return;

        dfs(grid, i - 1, j, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i, j + 1, n, m);
    }

    Solution() { memset(visited, false, sizeof(bool) * 302 * 302); }
};

int main() {
    vector<vector<char>> grid{
        vector<char>{'1', '1', '0', '0', '0'},
        vector<char>{'1', '1', '0', '0', '0'},
        vector<char>{'0', '0', '1', '0', '0'},
        vector<char>{'0', '0', '0', '1', '1'},
    };

    cout << Solution().numIslands(grid) << endl;

    return 0;
}
