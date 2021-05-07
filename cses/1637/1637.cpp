#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n + 1, -1);
    v[n] = 0;

    for (int i = n; i >= 0; i--) {
        if (v[i] == -1) continue;

        for (char c : to_string(i)) {
            int j = c - '0';

            if (i - j < 0) continue;
            if (v[i - j] == -1) {
                v[i - j] = v[i] + 1;
            } else {
                v[i - j] = min(v[i - j], v[i] + 1);
            }
        }
    }

    cout << v[0] << endl;

    return 0;
}
