#include <iostream>

using namespace std;

class Solution {
    int mem[110][110];

   public:
    int uniquePaths(int m, int n) { return unique(m, n, 0, 0); }

    int unique(int m, int n, int i, int j) {
        if (i >= m) return 0;
        if (j >= n) return 0;
        if (m == i + 1 && n == j + 1) return 1;

        if (mem[i][j] != -1) return mem[i][j];

        mem[i][j] = unique(m, n, i + 1, j) + unique(m, n, i, j + 1);

        return mem[i][j];
    }

    Solution() { memset(mem, -1, 110 * 110 * sizeof(int)); }
};

int main() {
    cout << Solution().uniquePaths(7, 3) << endl;

    return 0;
}
