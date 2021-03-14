#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

const int MAXN = 5, MAXM = 9;

// ###...###
// ..oo.....
// .....oo..
// .........
// ###...###

int co, plays;

// backtrack every possible move on every turn
void backtrack(char board[MAXN][MAXM], int left, int pl) {
    if (co > left) {
        co = left;
        plays = pl;
    } else if (co == left) {
        plays = min(plays, pl);
    }
    // co = min(co, left);

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXM; j++) {
            if (board[i][j] != 'o') continue;

            // up
            if (i > 1 && board[i - 1][j] == 'o' && board[i - 2][j] == '.') {
                board[i][j] = '.';
                board[i - 1][j] = '.';
                board[i - 2][j] = 'o';
                backtrack(board, left - 1, pl + 1);
                board[i][j] = 'o';
                board[i - 1][j] = 'o';
                board[i - 2][j] = '.';
            }
            // down
            if (i < MAXN - 2 && board[i + 1][j] == 'o' &&
                board[i + 2][j] == '.') {
                board[i][j] = '.';
                board[i + 1][j] = '.';
                board[i + 2][j] = 'o';
                backtrack(board, left - 1, pl + 1);
                board[i][j] = 'o';
                board[i + 1][j] = 'o';
                board[i + 2][j] = '.';
            }
            // left
            if (j > 1 && board[i][j - 1] == 'o' && board[i][j - 2] == '.') {
                board[i][j] = '.';
                board[i][j - 1] = '.';
                board[i][j - 2] = 'o';
                backtrack(board, left - 1, pl + 1);
                board[i][j] = 'o';
                board[i][j - 1] = 'o';
                board[i][j - 2] = '.';
            }
            // right
            if (j < MAXM - 2 && board[i][j + 1] == 'o' &&
                board[i][j + 2] == '.') {
                board[i][j] = '.';
                board[i][j + 1] = '.';
                board[i][j + 2] = 'o';
                backtrack(board, left - 1, pl + 1);
                board[i][j] = 'o';
                board[i][j + 1] = 'o';
                board[i][j + 2] = '.';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n;

    while (n--) {
        char board[MAXN][MAXM];

        co = 10000, plays = 10000;
        t = 0;

        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXM; j++) {
                cin >> board[i][j];
                if (board[i][j] == 'o') t++;
            }
        }

        backtrack(board, t, 0);
        cout << co << ' ' << plays << endl;
    }

    return 0;
}
