#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    ll y, x, diag;
    for (int i = 0; i < t; i++) {
        cin >> y >> x;
        y--;
        x--;

        if (y == x) {
            cout << y * (y + 1) + 1 << endl;
        } else if (y > x) {
            diag = y * (y + 1) + 1;

            if (y % 2 != 0) {
                cout << diag - (x - y) << endl;
            } else {
                cout << diag + (x - y) << endl;
            }
        } else {
            diag = x * (x + 1) + 1;
            if (x % 2 != 0) {
                cout << diag - (x - y) << endl;
            } else {
                cout << diag + (x - y) << endl;
            }
        }
    }

    return 0;
}
