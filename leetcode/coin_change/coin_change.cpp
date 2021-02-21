#include <bits/stdc++.h>

using namespace std;

class Solution {
    int mem[10100][13];

    const int INF = 1000000000;

   public:
    int coinChange(vector<int>& coins, int amount) {
        int r = change(coins, coins.size() - 1, amount);
        if (r >= INF) return -1;
        return r;
    }

    int change(vector<int>& coins, int i, int amount) {
        if (amount < 0) return INF;
        if (amount == 0) return 0;
        if (i < 0) return INF;
        if (mem[amount][i] != -1) return mem[amount][i];

        int m = INF;
        m = min(
            m, 1 + change(coins, i, amount - coins[i]));  // choose current coin
        m = min(m, change(coins, i - 1, amount));  // not choose current coin

        mem[amount][i] = m;

        return m;
    }

    Solution() { memset(mem, -1, 10100 * 13 * sizeof(int)); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> coins = vector<int>{186, 419, 83, 408};

    cout << Solution().coinChange(coins, 6249) << endl;

    return 0;
}
