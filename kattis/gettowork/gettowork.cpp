#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;

    int n, t, e, et, pass;
    for (int i = 1; i <= c; i++) {
        cin >> n >> t >> e;

        vector<vi> v(n);
        vi res(n, 0);

        for (int j = 0; j < e; j++) {
            cin >> et >> pass;
            v[et - 1].push_back(pass);
        }

        bool brk = false;

        for (int j = 0; j < n && !brk; j++) {
            if (j + 1 == t) continue;

            sort(v[j].begin(), v[j].end(), greater<int>());

            for (int k = 0, kk = v[j].size(); k < kk; k++) {
                if (v[j][k] == 0) {
                    brk = true;
                    break;
                }

                kk -= v[j][k] - 1;
                res[j]++;
            }
        }

        cout << "Case #" << i;
        if (brk) {
            cout << ": IMPOSSIBLE" << endl;
            continue;
        }

        cout << ": ";
        for (auto j : res) cout << j << ' ';
        cout << endl;
    }

    return 0;
}
