#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ld> vi;
typedef vector<bool> vb;

#define pb push_back

// const int mh = 12;
// const int sh = 720;
const ll ns = 10e9;

const ld tick = 1 / 12 * 10e-10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vi v(3);
    for (int tt = 1; tt <= t; tt++) {
        ld h = 0, m = 0, s = 0, nan = 0;
        cin >> v[0] >> v[1] >> v[2];

        v[0] = v[0] / 12 * 10e-11;  // degrees
        v[1] = v[1] / 12 * 10e-11;  // degrees
        v[2] = v[2] / 12 * 10e-11;  // degrees

        cout << v[0] << " " << v[1] << " " << v[2] << endl;

        h = v[0] / 30;
        m = v[1] / 6;
        s = v[2] / 6;
        // nan = 360 / (3600 * ns) * v[2];

        cout << "Case #" << tt << ": " << h << " " << m << " " << s << " "
             << nan << endl;
    }

    return 0;
}
