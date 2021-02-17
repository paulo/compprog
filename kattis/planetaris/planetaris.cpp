#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n >> a;

    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int t = 0;
    for (int i = 0; i < n && a >= 0; i++) {
        a -= v[i] + 1;
        t++;
    }

    if (a < 0) t--;

    cout << t << endl;

    return 0;
}
