#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define w(n) while (cin >> n)
#define pl(n) cout << n << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    w(n) {
        cin >> m;
        vi v(m);
        rep(i, m) cin >> v[i];
        sort(v.begin(), v.end());

        // dp basically tracks who is playing on a given turn and if
        // stan is going to win
        vb dp(n + 1, false);
        dp[0] = false;
        for (int i = 1; i <= n; i++) {
            for (auto p : v) {
                if (i - p == 0) {
                    dp[i] = true;
                    break;
                }
                // if i - p is not a winnable position, stan can move there
                // without ollie winning and so i is a winnable position
                if (i - p > 0 && !dp[i - p]) {
                    dp[i] = true;
                }
            }
        }

        if (dp[n]) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
    }

    return 0;
}
