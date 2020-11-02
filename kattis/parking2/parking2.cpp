#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        int mi = 100, ma = 0, aux;
        for (int j = 0; j < n; j++) {
            cin >> aux;

            mi = min(mi, aux);
            ma = max(ma, aux);
        }

        cout << (ma - mi) * 2 << endl;
    }

    return 0;
}
