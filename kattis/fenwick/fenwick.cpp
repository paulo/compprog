#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

// lowbit: https://www.quora.com/What-does-x-x-lowbit-do-in-C++
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    ll x, y, sum;
    cin >> n >> q;

    vll v(n + 1, 0);

    char op;
    for (int i = 0; i < q; i++) {
        cin >> op >> x;
        if (op == '+') {
            x++;
            cin >> y;
            while (x <= n) {
                v[x] += y;
                x += x & -x;
            }
        } else {
            sum = 0;
            while (x > 0) {
                sum += v[x];
                x -= x & -x;
            }

            cout << sum << "\n";
        }
    }

    return 0;
}
