#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, unordered_map<ll, bool>> mem;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// bool dp(ll a, ll b) {
// if (a == 0 && b != 0) return false;
// if (a != 0 && b == 0) return false;
// if (a < 0 || b < 0) return false;
// if (a == 0 && b == 0) return true;

// if (mem.find(a) != mem.end() && mem[a].find(b) != mem[a].end())
// return mem[a][b];
// if (mem.find(b) != mem.end() && mem[b].find(a) != mem[b].end())
// return mem[b][a];

// mem[a][b] = dp(a - 2, b - 1) || dp(a - 1, b - 2);
// mem[b][a] = mem[a][b];

// return mem[a][b];
// }

const ll MAXN = 10e5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<bool> dp(MAXN, false);
    dp[0] = true;

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp[i][j] = true;
        }
    }

    ll a, b;
    while (t-- > 0) {
        cin >> a >> b;

        ll d = gcd(a, b);
        cout << a << " " << b << endl;
        cout << d << endl;
        a /= d;
        b /= d;
        cout << a << " " << b << endl;

        // dp(a, b);
        // cout << "YES" << endl;
        // cout << "NO" << endl;
    }

    return 0;
}
