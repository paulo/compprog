#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

string s;
int x, y;

int dp[1010][2];

// c is the previous character
int solve(int i, char c) {
    if (i >= int(s.length())) return 0;
    if (dp[i][c == 'C' ? 0 : 1] != -1) return dp[i][c == 'C' ? 0 : 1];

    int cost = INT_MAX, added = 0;
    if (s[i] != '?') {
        if (s[i] == 'C' && c == 'J')
            added = y;
        else if (s[i] == 'J' && c == 'C')
            added = x;

        cost = min(cost, added + solve(i + 1, s[i]));
    } else {
        if (c == 'C') {
            cost = min(cost, solve(i + 1, 'C'));
            cost = min(cost, x + solve(i + 1, 'J'));
        } else {
            cost = min(cost, y + solve(i + 1, 'C'));
            cost = min(cost, solve(i + 1, 'J'));
        }
    }

    dp[i][c == 'C' ? 0 : 1] = cost;

    return cost;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        cin >> x >> y >> s;

        memset(dp, -1, 1010 * 2 * sizeof(int));

        int t = INT_MAX;
        if (s[0] == 'C' || s[0] == 'J') {
            t = solve(1, s[0]);
        } else {
            t = min(solve(1, 'C'), solve(1, 'J'));
        }

        cout << "Case #" << c << ": " << t << endl;
    }

    return 0;
}
