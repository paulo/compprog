#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

int co = 10000;

void backtrack(bool cavs[12], int left) {
    co = min(left, co);
    if (left == 1) return;

    for (int i = 0; i < 12; i++) {
        if (!cavs[i]) continue;
        if (i < 10 && cavs[i + 1] && !cavs[i + 2]) {
            cavs[i] = false;
            cavs[i + 1] = false;
            cavs[i + 2] = true;
            backtrack(cavs, left - 1);
            cavs[i] = true;
            cavs[i + 1] = true;
            cavs[i + 2] = false;
        }

        if (i > 1 && cavs[i - 1] && !cavs[i - 2]) {
            cavs[i] = false;
            cavs[i - 1] = false;
            cavs[i - 2] = true;
            backtrack(cavs, left - 1);
            cavs[i] = true;
            cavs[i - 1] = true;
            cavs[i - 2] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, pebs;
    cin >> n;

    char aux;
    while (n--) {
        bool cavs[12];
        pebs = 0;
        rep(i, 0, 12) {
            cin >> aux;
            if (aux == 'o') {
                pebs++;
                cavs[i] = true;
            } else
                cavs[i] = false;
        }

        co = 100;
        backtrack(cavs, pebs);
        cout << co << endl;
    }

    return 0;
}
