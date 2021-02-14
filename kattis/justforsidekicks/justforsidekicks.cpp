#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    ll vs[7];  // gem value
    for (int i = 1; i < 7; i++) cin >> vs[i];

    vi vfen[7];  // list of fenwick trees, one per gem type
    for (int i = 1; i < 7; i++) vfen[i] = vi(n + 1, false);

    vi vg(n + 1, 0);  // original gem position

    char c;
    int ind;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        ind = i;

        vg[i] = c - '0';

        while (ind <= n) {
            vfen[c - '0'][ind]++;
            ind += ind & -ind;
        }
    }

    ll sum = 0, pg;
    int qt, a1, a2;
    for (int i = 0; i < q; i++) {
        cin >> qt >> a1 >> a2;

        switch (qt) {
            case 1:
                pg = vg[a1];
                vg[a1] = a2;

                while (a1 <= n) {
                    vfen[pg][a1]--;
                    vfen[a2][a1]++;
                    a1 += a1 & -a1;
                }

                break;
            case 2:
                vs[a1] = a2;
                break;
            case 3:
                sum = 0;
                while (a2 > 0) {
                    for (int i = 1; i < 7; i++) {
                        sum += vfen[i][a2] * vs[i];
                    }

                    a2 -= a2 & -a2;
                }

                a1--;
                while (a1 > 0) {
                    for (int i = 1; i < 7; i++) {
                        sum -= vfen[i][a1] * vs[i];
                    }

                    a1 -= a1 & -a1;
                }

                cout << sum << "\n";

                break;
        }
    }

    return 0;
}
