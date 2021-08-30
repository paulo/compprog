#include <math.h>

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool mm[25][55][55];
vector<int> cars[25];

int fi, fj, gi, gj, n, m, x;

void consumeMatrix() {
    char aux;
    memset(mm, false, 25 * 55 * 55 * sizeof(bool));

    for (int j = 0; j < n + 2; j++) {
        cars[j] = vector<int>();
        for (int k = 0; k < m; k++) {
            cin >> aux;

            if (aux == 'F') {
                fi = j;
                fj = k;
            } else if (aux == 'G') {
                gi = j;
                gj = k;
            } else if (aux == 'X') {
                cars[j].push_back(k);
            }
        }
    }
}

// The motorway is constructed in such a way that the direction in which the
// cars travel alternates between the lanes, with cars in the first lane (the
// one closest to the starting point of the frog) moving to the right.
bool collision(int fi, int fj, int curr) {
    bool dirRight = (n % 2 == 0 && fi % 2 == 0) || (n % 2 != 0 && fi % 2 != 0);
    int cj = 0;

    for (auto c : cars[fi]) {
        if (dirRight) {
            cj = (c + curr) % m;
        } else {
            cj = (c - curr) % m;
            if (cj < 0) cj = m + cj;
        }

        if ((cj % m) == fj) return true;
    }

    return false;
}

// Road :: carPresent(const State& s) {
// int offset = (s.y%2==1)?width-(s.distance % width):s.distance % width;
// return lane(s.y)[(s.x+offset)%width]=='X';
// }

const int INF = 10000000;

// TODO: Check case where it is possible to solve but exactly at x
int solve(int curr, int fi, int fj) {
    if (curr > x) return INF;
    if (fi == gi && fj == gj) return curr;
    if (fi >= n + 2 || fi < 0) return INF;
    if (fj >= m || fj < 0) return INF;
    if (collision(fi, fj, curr)) return INF;
    if (mm[fi][fj][curr % m]) {
        // cout << "here " << fi << ' ' << fj << ' ' << curr << endl;
        return INF;  // state already visited, there are only m possible states
    }

    mm[fi][fj][curr % m] = true;

    // cout << "not here " << fi << ' ' << fj << ' ' << curr << endl;

    // cout << "here " << fi << ' ' << fj << ' ' << curr << endl;

    int res = INF;
    res = min(res, solve(curr + 1, fi - 1, fj));  // down
    res = min(res, solve(curr + 1, fi + 1, fj));  // up
    res = min(res, solve(curr + 1, fi, fj + 1));  // right
    res = min(res, solve(curr + 1, fi, fj - 1));  // left
    res = min(res, solve(curr + 1, fi, fj));      // stand still

    // cout << fi << ' ' << fj << ' ' << res << endl;

    return res;
}

int main() {
    int t, res;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> x >> n >> m;

        consumeMatrix();

        res = solve(0, fi, fj);

        if (res > x) {
            cout << "The problem has no solution." << endl;
        } else {
            cout << "The minimum number of turns is " << res << "." << endl;
        }
    }

    return 0;
}
