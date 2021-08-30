#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int n, k;
    for (int tt = 1; tt <= t; tt++) {
        cin >> n >> k;

        vi v(n + 2);
        v[0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> v[i + 1];
        }
        v[n + 1] = k;

        sort(v.begin(), v.end());

        vector<ld> interval;
        for (int i = 1; i < v.size(); i++) {
            ld aux = v[i] - v[i - 1];
            if (aux == 0) continue;
            if (i == 1 || i == v.size() - 1) {
                interval.push_back(aux);
            } else {
                aux = (aux - 1.0) / 2.0;
                if (ceil(aux) > 0) interval.push_back(ceil(aux));
                if (floor(aux) > 0) interval.push_back(floor(aux));
            }
        }

        sort(interval.begin(), interval.end(), greater<ld>());

        // for (int i = 0; i < interval.size(); i++) {
        // cout << interval[i] << endl;
        // }

        ld t = 0;
        if (interval.size() > 0) t += interval[0];
        if (interval.size() > 1) t += interval[1];

        cout << fixed << setprecision(8) << "Case #" << tt << ": " << t / ld(k)
             << endl;
    }

    return 0;
}
