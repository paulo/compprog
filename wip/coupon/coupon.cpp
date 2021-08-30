#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll MAXN = 100000;

// item -> previous is same or not -> current
vector<vector<int>> dp;

int n, m;

int solve(int i, bool same, int curr, vvi prices, vvi discounts) {
    if (i >= n) return 0;
    if (dp[i][curr] != -1) return dp[i][curr];

    int t = prices[i][curr];
    if (same) {
        t -= discounts[i - 1][curr];
        if (t < 0) t = 0;
    }

    int mi = INT_MAX;
    for (int j = 0; j < m; j++) {
        mi = min(mi, solve(i + 1, curr == j, j, prices, discounts));
    }

    dp[i][curr] = mi + t;

    // if (i == 0) {
    // cout << mi + t << endl;
    // }

    return mi + t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t-- > 0) {
        cin >> n >> m;

        vvi prices(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> prices[i][j];

        vvi discounts(n, vi(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> discounts[i][j];

        dp = vector<vector<int>>(n, vector<int>(m, -1));

        // memset(dp, -1, MAXN * MAXN * sizeof(int));

        int mi = INT_MAX;
        for (int i = 0; i < m; i++) {
            mi = min(mi, solve(0, 0, i, prices, discounts));
        }

        cout << mi << endl;
    }

    return 0;
}
