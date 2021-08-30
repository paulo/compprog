#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll t = 0, aux;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> aux;
        t += aux;
        v[i] = aux;
    }

    sort(v.begin(), v.end());
    ll median;
    if (n % 2 == 0) {
        median = ceil((double(v[n / 2]) + double(v[n / 2 + 1])) / 2.0);
    } else {
        median = v[(n + 1) / 2];
    }

    // ll m = floor(double(t) / double(n));
    ll tt = 0;
    for (int i = 0; i < n; i++) tt += abs(median - v[i]);

    cout << tt << endl;

    return 0;
}
