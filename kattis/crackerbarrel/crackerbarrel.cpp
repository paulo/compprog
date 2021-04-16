#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
    pq;

#define pb push_back

char mat[5][5];

void print() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool solved(char goal) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (mat[i][j] == goal) {
                return true;
            }
        }
    }
    return false;
}

bool solve(int left, char goal) {
    if (left == 1) return solved(goal);

    char aux;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (mat[i][j] != '_') {
                if (i > 1 && mat[i - 1][j] != '_' &&
                    mat[i - 2][j] == '_') {  // up right
                    aux = mat[i - 1][j];
                    mat[i - 2][j] = mat[i][j];
                    mat[i - 1][j] = '_';
                    mat[i][j] = '_';
                    if (solve(left - 1, goal)) return true;
                    mat[i][j] = mat[i - 2][j];
                    mat[i - 1][j] = aux;
                    mat[i - 2][j] = '_';
                }
                if (i > 1 && j > 1 && mat[i - 1][j - 1] != '_' &&
                    mat[i - 2][j - 2] == '_') {  // up left
                    aux = mat[i - 1][j - 1];
                    mat[i - 2][j - 2] = mat[i][j];
                    mat[i - 1][j - 1] = '_';
                    mat[i][j] = '_';
                    if (solve(left - 1, goal)) return true;
                    mat[i][j] = mat[i - 2][j - 2];
                    mat[i - 1][j - 1] = aux;
                    mat[i - 2][j - 2] = '_';
                }

                if (j < i - 1 && mat[i][j + 1] != '_' &&
                    mat[i][j + 2] == '_') {  // right
                    aux = mat[i][j + 1];
                    mat[i][j + 2] = mat[i][j];
                    mat[i][j + 1] = '_';
                    mat[i][j] = '_';
                    if (solve(left - 1, goal)) return true;
                    mat[i][j] = mat[i][j + 2];
                    mat[i][j + 1] = aux;
                    mat[i][j + 2] = '_';
                }
                if (j > 1 && mat[i][j - 1] != '_' &&
                    mat[i][j - 2] == '_') {  // left
                    aux = mat[i][j - 1];
                    mat[i][j - 2] = mat[i][j];
                    mat[i][j - 1] = '_';
                    mat[i][j] = '_';
                    if (solve(left - 1, goal)) return true;
                    mat[i][j] = mat[i][j - 2];
                    mat[i][j - 1] = aux;
                    mat[i][j - 2] = '_';
                }
                if (i < 3 && mat[i + 1][j] != '_' &&
                    mat[i + 2][j] == '_') {  // down
                    aux = mat[i + 1][j];
                    mat[i + 2][j] = mat[i][j];
                    mat[i + 1][j] = '_';
                    mat[i][j] = '_';
                    if (solve(left - 1, goal)) return true;
                    mat[i][j] = mat[i + 2][j];
                    mat[i + 1][j] = aux;
                    mat[i + 2][j] = '_';
                }
                if (i < 3 && mat[i + 1][j + 1] != '_' &&
                    mat[i + 2][j + 2] == '_') {  // down right
                    aux = mat[i + 1][j + 1];
                    mat[i + 2][j + 2] = mat[i][j];
                    mat[i + 1][j + 1] = '_';
                    mat[i][j] = '_';
                    if (solve(left - 1, goal)) return true;
                    mat[i][j] = mat[i + 2][j + 2];
                    mat[i + 1][j + 1] = aux;
                    mat[i + 2][j + 2] = '_';
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char c, aux;

    while (cin >> c >> c && c != '*') {
        memset(mat, ' ', 5 * 5 * sizeof(char));

        int count = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < i + 1; j++) {
                cin >> aux;
                if (aux != '_') count++;

                cin >> mat[i][j];
            }
        }

        if (solve(count, c)) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
