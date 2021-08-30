#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

const int MAXN = 2010;
int matrix[MAXN][MAXN];
int orig[MAXN][MAXN];

void tryFix(int n, int m, int i, int j) {
    for (; i < n; i++) {
        for (; j < m; j++) {
            if (i == 0 && j == 0) {
                matrix[i][j] = 1;
            } else if (i == 0) {  // first row
                matrix[i][j] = matrix[i][j - 1] + 1;
            } else if (j == 0) {  // first column
                matrix[i][j] = matrix[i - 1][j] + 1;
                // if (i == 1 && matrix[0][j + 1] == matrix[i][j])
                // matrix[i][j]++;
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]) + 1;
            }
        }
    }
}

bool valid(int n, int m) {
    if (m > 1) {
        for (int i = 0; i < n; i++) {
            int last = -1;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] <= last) {
                    return false;
                } else
                    last = matrix[i][j];
            }
        }
    }

    if (n > 1) {
        for (int j = 0; j < m; j++) {
            int last = -1;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] <= last) {
                    return false;
                } else
                    last = matrix[i][j];
            }
        }
    }

    if (m > 2 && n > 2) {
        if (matrix[0][1] % 2 == matrix[1][0] % 2) {
            matrix[0][1]++;
            tryFix(n, m, 0, 2);
            return false;
        }
        if (matrix[n - 1][1] % 2 == matrix[n - 2][0] % 2) {
            matrix[n - 2][0]++;  // TODO: Do this for the other cases, carefull
                                 // not to change original cells
            tryFix(n, m, n - 2, 1);
            return false;
        }
        if (matrix[n - 2][m - 1] % 2 == matrix[n - 1][m - 2] % 2) {
            matrix[n - 2][m - 1]++;
            tryFix(n, m, n - 1, 0);
            return false;
        }
        if (matrix[0][m - 2] % 2 == matrix[1][m - 1] % 2) {
            matrix[0][m - 2]++;
            tryFix(n, m, 0, m - 1);
            return false;
        }
    }

    return true;
}

ll total(int n, int m) {
    ll t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) t += matrix[i][j];
    }
    return t;
}

int main() {
    int n, m, aux;
    cin >> n >> m;

    memset(matrix, -1, MAXN * MAXN * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> aux;
            matrix[i][j] = aux;
            orig[i][j] = aux;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                if (i == 0 && j == 0) {
                    matrix[i][j] = 1;
                } else if (i == 0) {  // first row
                    matrix[i][j] = matrix[i][j - 1] + 1;
                } else if (j == 0) {  // first column
                    matrix[i][j] = matrix[i - 1][j] + 1;
                    // if (i == 1 && matrix[0][j + 1] == matrix[i][j])
                    // matrix[i][j]++;
                } else {
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]) + 1;
                }

                if (i == 1 && j == 0 && matrix[i][j] % 2 == matrix[0][1] % 2) {
                    matrix[i][j]++;
                }

                // Try and fix corners as they come
                // if (i == n - 1 && j == m - 2 &&
                // matrix[n - 2][m - 1] % 2 == matrix[n - 1][m - 2] % 2) {
                // matrix[i][j]++;
                // }

                // if (i == 1 && j == m - 1 &&
                // matrix[0][m - 2] % 2 == matrix[i][j] % 2) {
                // matrix[i][j]++;
                // }

                // if (i == n - 1 && j == 1 &&
                // matrix[n - 1][1] % 2 == matrix[n - 2][0] % 2) {
                // matrix[i][j]++;
                // }

                // if (i == 0 && j == m - 2 && matrix[1][m - 1] != 0 &&
                // matrix[i][j] % 2 == matrix[1][m - 1] % 2) {
                // matrix[i][j]++;
                // }

                // if (i == n - 2 && j == 0 && matrix[n - 1][1] != 0 &&
                // matrix[i][j] % 2 == matrix[n - 1][1] % 2) {
                // matrix[i][j]++;
                // }

                // if (i == n - 2 && j == m - 1 && matrix[n - 1][m - 2] != 0 &&
                // matrix[i][j] % 2 == matrix[n - 1][m - 2] % 2) {
                // matrix[i][j]++;
                // }
            }
        }
    }

    !valid(n, m);
    !valid(n, m);
    !valid(n, m);

    // for (int i = 0; i < n; i++) {
    // for (int j = 0; j < m; j++) cout << matrix[i][j] << ' ';
    // cout << endl;
    // }

    // if (!valid(n, m) && n > 10) throw std::runtime_error("invalid");
    if (!valid(n, m)) {
        cout << -1 << endl;
        return 0;
    }

    // for (int i = 0; i < n; i++) {
    // for (int j = 0; j < m; j++) cout << matrix[i][j] << ' ';
    // cout << endl;
    // }
    cout << total(n, m) << endl;

    return 0;
}

