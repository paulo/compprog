#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n + 1, 0);
    v[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && i - j >= 0; j++) {
            v[i] = (v[i] + v[i - j]) % (1000000007);
        }
    }

    cout << v[n] << endl;
    return 0;
}
