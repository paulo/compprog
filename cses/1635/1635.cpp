#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> r(x + 1, 0);
    r[0] = 1;
    for (int i = 0; i <= x; i++) {
        if (r[i] == 0) continue;

        for (auto c : v) {
            if (i + c <= x)
                r[i + c] =
                    r[i + c] == 0 ? r[i] : (r[i + c] + r[i]) % 1000000007;
        }
    }

    cout << r[x] << endl;

    return 0;
}
