#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1010;
const int MAXX = 100010;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);
    vector<vector<ll>> mem =
        vector<vector<ll>>(MAXN, vector<ll>(MAXX, INT_MIN));

    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << mem[n - 1][x] << endl;

    return 0;
}
