#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

const int MAXN = 10000;

// simulate board
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> m;

    int board[MAXN][MAXN][MAXN];
    // memset(board, -1, MAXN * MAXN * MAXN * sizeof(int));

    // Using cube coordinates to represent the hexagon grid
    // https://www.redblobgames.com/grids/hexagons/#coordinates-cube
    int x = 5000, y = -2500, z = -2500;
    board[x][y][z] = 1;
    bool even;
    for (int i = 0; i <= MAXN; i++) {
        

        even = currx % 2 == 0;

        if (board[currx - 1][curry + 1] == -1) {
            curry++;
        } else if (board[currx][curry + 1] == -1) {
            curry++;
            currx--;
        } else if (board[currx - 1][curry] ==)
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
    }

    return 0;
}
