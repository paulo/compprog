#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int cost = 0;
        for (int i = 0; i < n - 1; i++) {
            int min = INT_MAX, minind = 0;
            for (int j = i; j < n; j++) {  // small input
                if (v[j] < min) {
                    min = v[j];
                    minind = j;
                }
            }

            reverse(v.begin() + i, v.begin() + minind + 1);

            cost += minind - i + 1;
        }

        cout << "Case #" << c << ": " << cost << endl;
    }

    return 0;
}
