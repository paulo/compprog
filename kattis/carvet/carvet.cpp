#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int co = 0, r, c, n, m;
vector<int> curr, best, aux, aux2;
const int MAXN = 255;
int board[MAXN][MAXN];

// ei and ej is the space currently empty
// dir maintains the previous direction (1 up, 2 down, 3 left, 4 right)
void backtrack(int ei, int ej, int dir) {
    if (r - 1 == ei && c - 1 == ej) {
        if (best.size() == 0 || best.size() > curr.size()) {
            best = curr;
        } else if (best.size() != 0 && best.size() == curr.size()) {
            aux = curr;
            aux2 = best;
            for (int z = 0; z < int(aux.size()); z++) {
                if (aux[z] < aux2[z]) {
                    best = aux;
                    break;
                } else if (aux2[z] > aux[z])
                    break;
            }
        }
    }

    // can move from up
    if (dir != 1 && ei > 1 && board[ei - 1][ej] == board[ei - 2][ej]) {
        board[ei][ej] = board[ei - 1][ej];
        board[ei - 1][ej] = board[ei - 2][ej];
        board[ei - 2][ej] = -1;
        curr.push_back(board[ei - 1][ej]);
        backtrack(ei - 2, ej, 2);
        curr.pop_back();
        board[ei - 1][ej] = board[ei][ej];
        board[ei - 2][ej] = board[ei][ej];
        board[ei][ej] = -1;
    }

    // down
    if (dir != 2 && ei < n - 2 && board[ei + 1][ej] == board[ei + 2][ej]) {
        board[ei][ej] = board[ei + 1][ej];
        board[ei + 1][ej] = board[ei + 2][ej];
        board[ei + 2][ej] = -1;
        curr.push_back(board[ei + 1][ej]);
        backtrack(ei + 2, ej, 1);
        curr.pop_back();
        board[ei + 1][ej] = board[ei][ej];
        board[ei + 2][ej] = board[ei][ej];
        board[ei][ej] = -1;
    }

    // left
    if (dir != 3 && ej > 1 && board[ei][ej - 1] == board[ei][ej - 2]) {
        board[ei][ej] = board[ei][ej - 1];
        board[ei][ej - 1] = board[ei][ej - 2];
        board[ei][ej - 2] = -1;
        curr.push_back(board[ei][ej - 1]);
        backtrack(ei, ej - 2, 4);
        curr.pop_back();
        board[ei][ej - 1] = board[ei][ej];
        board[ei][ej - 2] = board[ei][ej];
        board[ei][ej] = -1;
    }

    // right
    if (dir != 4 && ej < m - 2 && board[ei][ej + 1] == board[ei][ej + 2]) {
        board[ei][ej] = board[ei][ej + 1];
        board[ei][ej + 1] = board[ei][ej + 2];
        board[ei][ej + 2] = -1;
        curr.push_back(board[ei][ej + 1]);
        backtrack(ei, ej + 2, 3);
        curr.pop_back();
        board[ei][ej + 1] = board[ei][ej];
        board[ei][ej + 2] = board[ei][ej];
        board[ei][ej] = -1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ei, ej;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                ei = i;
                ej = j;
            }
        }
    }

    cin >> r >> c;

    backtrack(ei, ej, 0);

    if (best.size() == 0) {
        cout << "impossible" << endl;
        return 0;
    }

    for (auto x : best) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
