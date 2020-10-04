#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    int m, n, k, tt;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        vector<vector<char>> vi(n);

        for (int j = 0; j < n; j++) {
            vector<char> vii(m);
            for (int k = 0; k < m; k++) {
                cin >> vii[k];
            }
            vi[j] = vii;
        }

        bool found = false;
        char current;
        for (int k1 = 0; k1 < n; k1++) {
            if (found) {
                break;
            }

            for (int k2 = 0; k2 < m; k2++) {
                if (found) {
                    break;
                }
                if (vi[k1][k2] == '.') {
                    continue;
                }

                current = vi[k1][k2];

                // check down
                for (tt = 1; tt < k && k1 + tt < n; tt++) {
                    if (current != vi[k1 + tt][k2]) {
                        break;
                    }
                }
                if (tt == k) found = true;

                // check left
                for (tt = 1; tt < k && k2 - tt >= 0; tt++) {
                    if (current != vi[k1][k2 - tt]) {
                        break;
                    }
                }
                if (tt == k) found = true;

                // check right
                for (tt = 1; tt < k && k2 + tt < m; tt++) {
                    if (current != vi[k1][k2 + tt]) {
                        break;
                    }
                }
                if (tt == k) found = true;

                // check down right
                for (tt = 1; tt < k && k1 + tt < n && k2 + tt < m; tt++) {
                    if (current != vi[k1 + tt][k2 + tt]) {
                        break;
                    }
                }

                if (tt == k) found = true;

                // check down left
                for (tt = 1; tt < k && k1 + tt < n && k2 - tt >= 0; tt++) {
                    // mem[k1 + tt][k2 - tt] = true;
                    if (current != vi[k1 + tt][k2 - tt]) {
                        break;
                    }
                }

                if (tt == k) found = true;
            }
        }

        if (!found) continue;

        if (current == 'o')
            p2++;
        else
            p1++;
    }

    cout << p1 << ':' << p2 << endl;

    return 0;
}
