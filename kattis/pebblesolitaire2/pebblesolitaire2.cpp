#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int co;
const int MAXN = 23;
unordered_map<int, int> m;  // for memoization

void backtrack(bool cavs[MAXN], int left, int mask) {
    co = min(left, co);
    if (m.find(mask) != m.end() || left == 1) return;

    for (int i = 0; i < MAXN; i++) {
        if (!cavs[i]) continue;
        if (i < MAXN - 2 && cavs[i + 1] && !cavs[i + 2]) {
            cavs[i] = false;
            cavs[i + 1] = false;
            cavs[i + 2] = true;
            mask &= ~(1 << i);
            mask &= ~(1 << (i + 1));
            mask |= (1 << (i + 2));
            backtrack(cavs, left - 1, mask);
            cavs[i] = true;
            cavs[i + 1] = true;
            cavs[i + 2] = false;
            mask |= (1 << i);
            mask |= (1 << (i + 1));
            mask &= ~(1 << (i + 2));
        }

        if (i > 1 && cavs[i - 1] && !cavs[i - 2]) {
            cavs[i] = false;
            cavs[i - 1] = false;
            cavs[i - 2] = true;
            mask &= ~(1 << i);
            mask &= ~(1 << (i - 1));
            mask |= (1 << (i - 2));
            backtrack(cavs, left - 1, mask);
            cavs[i] = true;
            cavs[i - 1] = true;
            cavs[i - 2] = false;
            mask |= (1 << i);
            mask |= (1 << (i - 1));
            mask &= ~(1 << (i - 2));
        }
    }

    m[mask] = co;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, pebs;
    cin >> n;

    char aux;
    while (n--) {
        bool cavs[MAXN];
        pebs = 0;
        int mask = 0;
        rep(i, 0, MAXN) {
            cin >> aux;
            if (aux == 'o') {
                pebs++;
                cavs[i] = true;
                mask |= (1 << i);
            } else
                cavs[i] = false;
        }

        co = 100;
        backtrack(cavs, pebs, mask);
        cout << co << endl;
    }

    return 0;
}
