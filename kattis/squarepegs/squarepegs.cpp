#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vi v(n), v2(m + k);
    // Convert everything to radius
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> v2[i];
    for (int i = m; i < m + k; i++) {
        cin >> v2[i];
        v2[i] = floor(sqrt(2 * v2[i] * v2[i]) / 2.0);
    }

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    int i = 0, j = 0, t = 0;
    while (i < n && j < m + k) {
        if (v[i] > v2[j]) {
            t++;
            j++;
        }
        i++;
    }

    cout << t << endl;

    return 0;
}
