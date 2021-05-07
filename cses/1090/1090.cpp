#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    ll curr = 0, t = 1, c = 0;
    int i = 0, j = n - 1;
    while (i < n && j >= i) {
        if (c == 2) {
            curr = 0;
            t++;
            c = 0;
        }
        if (curr + v[i] <= x) {
            curr += v[i];
            i++;
            c++;
        } else if (curr + v[j] <= x) {
            curr += v[j];
            j--;
            c++;
        } else {
            curr = 0;
            t++;
        }
    }

    cout << t << endl;

    return 0;
}
