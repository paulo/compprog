#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

vi a, t;

int f(int i, int x) {
    if (t[i] == 1) {
        return x + a[i];
    } else if (t[i] == 2) {
        return max(x, a[i]);
    } else {
        return min(x, a[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a = vi(n);
    t = vi(n);
    rep(i, 0, n) cin >> a[i] >> t[i];

    int q, qi;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> qi;

        vector<vi> dp(n, vi());
        dp[0] = f(0, qi);
        for (int j = 1; j < n; j++) {
            dp[j] = f(j, dp[j - 1]);
        }

        cout << dp[n - 1] << endl;
    }

    return 0;
}
