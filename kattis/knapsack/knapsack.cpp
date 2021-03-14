#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back

// textbook knapsack problem
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, n;
    while (cin >> c >> n) {
        vi v(n), w(n);
        rep(i, n) cin >> v[i] >> w[i];

        vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= c; j++) {
                dp[i][j] = dp[i - 1][j];
                if (w[i - 1] <= j) {  // fits on current capacity
                    dp[i][j] =
                        max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
                }
            }
        }

        int i = n, j = c;
        vi res;

        while (dp[i][j] != 0 && i > 0 && j > 0) {
            if (dp[i][j] == dp[i - 1][j]) {
                i--;
            } else {
                i--;
                res.pb(i);
                j -= w[i];
            }
        }

        cout << res.size() << endl;
        for (auto x : res) cout << x << ' ';
        cout << endl;
    }

    return 0;
}
