#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vii v(n);
    int aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        v[i] = make_pair(aux, i);
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    // Carry the books to see if it's possible
    int i = 1, j = 0;
    while (i < n) {
        if (v[i].first >= v[j].first) {
            v[i].first -= v[j].first;
            v[j].first = 0;
        } else {
            v[j].first -= v[i].first;
            v[i].first = 0;
        }

        if (v[i].first == 0) i++;
        if (v[j].first == 0) j++;
    }

    if (v[0].first != 0) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < n; i++) cout << v[i].second + 1 << ' ';
        cout << endl;
    }

    return 0;
}
