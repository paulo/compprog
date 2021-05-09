#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> size(n);
    vector<ll> aps(n);

    for (int i = 0; i < n; i++) cin >> size[i];
    for (int i = 0; i < m; i++) cin >> aps[i];

    sort(size.begin(), size.end());
    sort(aps.begin(), aps.end());

    int i = 0, j = 0, t = 0;
    while (i < m && j < n) {
        if (abs(aps[i] - size[j]) <= k) {
            i++;
            j++;
            t++;
        } else if (aps[i] > size[j]) {
            j++;
        } else {
            i++;
        }
    }

    cout << t << endl;

    return 0;
}
