#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 300;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // problem that we want at the beginning
    swap(v[p], v[0]);

    int tn = 0, tt = 0, to = 0;

    sort(v.begin() + 1, v.end());

    for (int i = 0; i < n; i++) {
        if (to + v[i] > MAXN) break;

        tt += to + v[i];
        to += v[i];
        tn++;
    }

    cout << tn << ' ' << tt << endl;

    return 0;
}
