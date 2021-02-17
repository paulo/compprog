#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, s;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        vi v(3 * n);
        for (int j = 0; j < n * 3; j++) cin >> v[j];

        sort(v.begin(), v.end(), greater<int>());

        s = 0;

        for (int j = 0; j < n; j++) s += v[j * 2 + 1];
        cout << s << endl;
    }

    return 0;
}
