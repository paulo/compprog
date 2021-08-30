#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

const int MAXN = 1001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int n, b;
    for (int tt = 1; tt <= t; tt++) {
        cin >> n >> b;

        vi v(n);
        rep(i, 0, n) cin >> v[i];

        // counting sort
        vi cs(MAXN, 0);
        rep(i, 0, n) cs[v[i]]++;
        rep(i, 1, MAXN) cs[i] += cs[i - 1];

        vi sorted(n, 0);
        for (int i = 0; i < n; i++) {
            sorted[cs[v[i]] - 1] = v[i];
            cs[v[i]]--;
        }

        ll c = 0, total = 0, i = 0;
        while (c + sorted[i] <= b && i < n) {
            c += sorted[i];
            total++;
            i++;
        }
        cout << "Case #" << tt << ": " << total << endl;
    }

    return 0;
}
