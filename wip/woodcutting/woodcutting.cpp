#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed;
    cout << setprecision(3);

    int t, n, w, aux;
    cin >> t;

    while (t-- > 0) {
        cin >> n >> w;
        vii v;
        vi c(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < w; j++) {
                cin >> aux;
                v.push_back(make_pair(aux, i));
            }
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.length(); i++) {
            c[v[i].second] = v[i].first;
        }

        float t = 0;
        for (int i = 0; i < c.length(); i++) {
            t += c[i];
        }

        cout << t / c.size() << endl;
    }

    return 0;
}
