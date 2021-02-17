#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int t = 0, mx = 0;
    for (int i = 0; i < n && x - v[i] >= 0; i++) {
        if (mx + v[i] > x) break;
        t++;
        mx = max(mx, v[i]);
    }

    if (t == 0)
        cout << 1 << endl;
    else
        cout << t << endl;

    return 0;
}
