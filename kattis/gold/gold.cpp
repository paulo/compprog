#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<char> vc;

#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define w(n) while (cin >> n)
#define pl(n) cout << n << endl

const int MAXN = 55;
bool dp[MAXN][MAXN];
int golds = 0;

// ########
// #...GTG#
// #..PG.G#
// #...G#G#
// #..TG.G#
// ########
void walk(int pi, int pj, int h, int w, vector<vector<char>> board) {
    if (dp[pi][pj]) return;
    dp[pi][pj] = true;

    if (board[pi][pj] == 'G') golds++;
    if (board[pi][pj] == 'T' || board[pi][pj] == '#') return;

    if (board[pi - 1][pj] == 'T') return;
    if (board[pi][pj - 1] == 'T') return;
    if (board[pi + 1][pj] == 'T') return;
    if (board[pi][pj + 1] == 'T') return;

    walk(pi - 1, pj, h, w, board);
    walk(pi + 1, pj, h, w, board);
    walk(pi, pj - 1, h, w, board);
    walk(pi, pj + 1, h, w, board);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, h;
    cin >> w >> h;

    int ii, jj;
    vector<vc> v(h, vc(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'P') {
                ii = i;
                jj = j;
            }
        }
    }

    memset(dp, false, MAXN * MAXN * sizeof(bool));

    walk(ii, jj, h, w, v);

    cout << golds << endl;

    return 0;
}
