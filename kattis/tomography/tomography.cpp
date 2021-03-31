#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    ll tr = 0, tc = 0;
    cin >> m >> n;

    vi rows(m);
    for (int i = 0; i < m; i++) {
        cin >> rows[i];
        tr += rows[i];
    }

    vi cols(n);
    for (int i = 0; i < n; i++) {
        cin >> cols[i];
        tc += cols[i];
    }

    // greedily fill out the bigger columns
    int ind = 0;
    while (tr > 0 && ind < m) {
        sort(cols.begin(), cols.end(), greater<int>());
        int given = rows[ind];

        if (given > n) break;
        for (int i = 0; given > 0 && i < n; i++) {
            if (cols[i] > 0) {
                cols[i]--;
                given--;
                tr--;
                tc--;
            }
        }

        if (given) break;
        ind++;
    }

    if (tr == 0 && tc == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

