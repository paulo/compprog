#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define w(n) while (cin >> n)
#define pl(n) cout << n << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i = 1, q, qi, res, diff;
    w(n) {
        cout << "Case " << i << ":" << endl;

        vi v(n);
        rep(j, n) cin >> v[j];

        vi v2;
        for (int k = 0; k < n - 1; k++) {
            for (int z = k + 1; z < n; z++) {
                v2.pb(v[k] + v[z]);
            }
        }

        sort(v2.begin(), v2.end());

        cin >> q;
        rep(j, q) {
            cin >> qi;
            res = 0, diff = q;

            for (int k = 0; k < int(v2.size()); k++) {
                if (v2[k] == qi) {
                    res = qi;
                    break;
                } else {
                    if (abs(v2[k] - qi) <= diff || res == 0) {
                        res = v2[k];
                        diff = abs(qi - v2[k]);
                    } else
                        break;
                }
            }

            cout << "Closest sum to " << qi << " is " << res << "." << endl;
        }

        i++;
    }

    return 0;
}
