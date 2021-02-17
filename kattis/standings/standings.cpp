#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    ll n, aux, sum;
    string s;
    while (t-- > 0) {
        cin >> n;
        vii v(n);
        for (int i = 0; i < n; i++) {
            cin >> s >> aux;

            v[i] = make_pair(aux, i);
        }

        sort(v.begin(), v.end());

        sum = 0;
        for (int i = 0; i < n; i++) sum += abs(i + 1 - v[i].first);

        cout << sum << endl;
    }

    return 0;
}
