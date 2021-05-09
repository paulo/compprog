#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int MAXM = 105;

vector<int> v(MAXN);
int n, m;

vector<vector<int>> mem(MAXN, vector<int>(MAXM, -1));

int dp(int i, int prev) {
    if (i == n) return 1;
    if (mem[i][prev] != -1) return mem[i][prev];

    if (v[i] != 0) {
        if (prev == 0 || v[i] == prev || v[i] == prev - 1 || v[i] == prev + 1)
            return dp(i + 1, v[i]);
        else
            return 0;
    }

    int from = 1, to = m;
    if (i != 0) {
        from = max(prev - 1, 1), to = min(prev + 1, m);
    }

    int c = 0;
    for (int k = from; k <= to; k++) c = (c + dp(i + 1, k)) % 1000000007;

    mem[i][prev] = c;

    return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << dp(0, 0) << endl;

    return 0;
}
