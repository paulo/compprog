#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back

char mat[51][51];
bool visited[51][51];

bool up(char c) {
    return c == '0' || c == '4' || c == '1' || c == '5' || c == '2' ||
           c == '6' || c == '3' || c == '7';
}

bool down(char c) {
    return c == '0' || c == '4' || c == '8' || c == 'C' || c == '1' ||
           c == '5' || c == '9' || c == 'D';
}

bool left(char c) {
    return c == '0' || c == '4' || c == '8' || c == 'C' || c == '2' ||
           c == '6' || c == 'A' || c == 'E';
}

bool right(char c) {
    return c == '0' || c == '8' || c == '1' || c == '9' || c == '2' ||
           c == 'A' || c == '3' || c == 'B';
}

bool noSol, multiple;

void dfs(pair<int, int> curr, pair<int, int> prev, int h, int w) {
    if (curr.first >= h || curr.second >= w || curr.first < 0 ||
        curr.second < 0) {
        noSol = false;
        return;
    }

    if (visited[curr.first][curr.second]) {
        multiple = true;
        return;
    }

    visited[curr.first][curr.second] = true;

    if (up(mat[curr.first][curr.second]) && curr.first - 1 != prev.first)
        dfs({curr.first - 1, curr.second}, curr, h, w);
    if (left(mat[curr.first][curr.second]) && curr.second - 1 != prev.second)
        dfs({curr.first, curr.second - 1}, curr, h, w);
    if (right(mat[curr.first][curr.second]) && curr.second + 1 != prev.second)
        dfs({curr.first, curr.second + 1}, curr, h, w);
    if (down(mat[curr.first][curr.second]) && curr.first + 1 != prev.first)
        dfs({curr.first + 1, curr.second}, curr, h, w);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    char aux;
    while (cin >> h >> w && h != 0 && w != 0) {
        memset(mat, 0, 51 * 51 * sizeof(char));
        memset(visited, false, 51 * 51 * sizeof(bool));

        noSol = true;
        multiple = false;
        pair<int, int> o, prev;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> aux;
                mat[i][j] = aux;
                // track an opening from where to start
                if (i == 0 && up(aux)) {
                    o = {i, j};
                    prev = {-1, j};
                }
                if (j == 0 && left(aux)) {
                    o = {i, j};
                    prev = {i, -1};
                }
                if (i == h - 1 && down(aux)) {
                    o = {i, j};
                    prev = {h, j};
                }
                if (j == w - 1 && right(aux)) {
                    o = {i, j};
                    prev = {i, w};
                }
            }
        }

        dfs(o, prev, h, w);

        int cells = h * w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (visited[i][j]) cells--;
            }
        }

        if (noSol) {
            cout << "NO SOLUTION" << endl;
        } else if (cells > 0) {
            cout << "UNREACHABLE CELL" << endl;
        } else if (multiple) {
            cout << "MULTIPLE PATHS" << endl;
        } else {
            cout << "MAZE OK" << endl;
        }
    }

    return 0;
}
