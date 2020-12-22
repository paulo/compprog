#include <iostream>
#include <vector>

using namespace std;

// Every row has the same number of black squares as it has white squares.
// Every column has the same number of black squares as it has white squares.
// No row or column has 3 or more consecutive squares of the same color.
int main() {
    int n;
    cin >> n;

    bool valid = true;

    vector<int> blackCols(n, 0);
    vector<vector<char>> v(n, vector<char>(n));

    char aux;
    for (int i = 0; i < n; i++) {
        int rb = 0;
        for (int j = 0; j < n; j++) {
            cin >> aux;
            v[i][j] = aux;

            if (aux == 'B') {
                blackCols[j]++;
                rb++;
            }
        }

        if (rb != n / 2) valid = false;
    }

    for (int i = 0; i < n; i++) {
        if (blackCols[i] != n / 2) valid = false;
    }

    // check consecutive
    int cc = 0, rc = 0;
    bool lastRB = false, lastCB = false;
    // WWBBWB
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'B') {
                if (lastCB) {
                    cc++;
                } else {
                    cc = 1;
                    lastCB = true;
                }
            } else {
                if (!lastCB) {
                    cc++;
                } else {
                    cc = 1;
                    lastCB = false;
                }
            }

            if (v[j][i] == 'B') {
                if (lastRB) {
                    rc++;
                } else {
                    rc = 1;
                    lastRB = true;
                }
            } else {
                if (!lastRB) {
                    rc++;
                } else {
                    rc = 1;
                    lastRB = false;
                }
            }

            if (cc >= 3 || rc >= 3) valid = false;
        }
        lastRB = false;
        lastCB = false;
        cc = 0;
        rc = 0;
    }

    if (valid)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
