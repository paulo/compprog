#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> m(n * n);
    char aux;
    for (int i = 0; i < n * n; i++) {
        cin >> aux;
        m[i] = aux == '*';
    }

    if (m[n * n - 1]) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v(n * n, 0);
    v[0] = 1;

    for (int i = 0; i < n * n; i++) {
        if (v[i] == 0 || m[i]) continue;

        if (i % n < n - 1) {  // not on the last column
            v[i + 1] = (v[i + 1] + v[i]) % 1000000007;
        }
        if (i + n < n * n) {  // not on the last row
            v[i + n] = (v[i + n] + v[i]) % 1000000007;
        }
    }

    cout << v[n * n - 1] % 1000000007 << endl;

    return 0;
}
