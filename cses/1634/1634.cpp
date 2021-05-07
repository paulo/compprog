#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> r(x + 1, -1);
    r[0] = 0;
    for (int i = 0; i <= x; i++) {
        if (r[i] == -1) continue;

        for (auto c : v) {
            if (i + c > x) continue;

            r[i + c] = r[i + c] == -1 ? r[i] + 1 : min(r[i] + 1, r[i + c]);
        }
    }

    cout << r[x] << endl;

    return 0;
}
