#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int cost(string x, string y, int a, int b) {
    if (x[a] == x[b]) return 0;
    return 1;
}

int distance(string x, string y, int a, int b) {
    if (a == 0 && b == 0) return cost(x, y, a, b);

    int d = INT_MAX;
    d = min(d, distance(x, y, a, b-1) + 1);
    d = min(d, distance(x, y, a, b-1) + 1);
    d = min(d, distance(x, y, a, b-1) + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string p, s;
    cin >> p;

    int n;
    cin >> n;

    while (n-- > 0) {
        cin >> s;
    }

    return 0;
}
