#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l, n, d;
    cin >> l >> d >> n;

    vll v(n + 2);

    // Add extra birds at beginning and end to avoid special cases
    v[0] = 6 - d;
    for (int i = 1; i <= n; i++) cin >> v[i];
    v[n + 1] = l + d - 6;
    sort(v.begin(), v.end());

    int total = 0;
    for (int i = 0; i < n + 1; i++) total += (v[i + 1] - v[i]) / d - 1;

    cout << total << endl;

    return 0;
}
