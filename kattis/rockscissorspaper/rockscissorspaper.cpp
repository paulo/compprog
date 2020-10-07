#include <iostream>
#include <vector>

using namespace std;

bool wins(char c1, char c2) {
    return ((c1 == 'P' && c2 == 'R') || (c1 == 'S' && c2 == 'P') ||
            (c1 == 'R' && c2 == 'S'));
}

char letterFor(vector<vector<char>> &m, int i, int j, int r, int c) {
    if (i < r - 1 && wins(m[i + 1][j], m[i][j])) return m[i + 1][j];
    if (i > 0 && wins(m[i - 1][j], m[i][j])) return m[i - 1][j];
    if (j < c - 1 && wins(m[i][j + 1], m[i][j])) return m[i][j + 1];
    if (j > 0 && wins(m[i][j - 1], m[i][j])) return m[i][j - 1];

    return m[i][j];
}

int main() {
    int t;
    cin >> t;

    int r, c, n;
    for (int k = 0; k < t; k++) {
        cin >> r >> c >> n;

        vector<vector<char>> m(r);
        vector<vector<char>> newM(r);
        for (int i = 0; i < r; i++) {
            m[i] = vector<char>(c);
            newM[i] = vector<char>(c);
            for (int j = 0; j < c; j++) {
                cin >> m[i][j];
            }
        }

        for (int z = 0; z < n; z++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    newM[i][j] = letterFor(m, i, j, r, c);
                }
            }
            m = newM;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << m[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
