#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back

const int MAXN = 1010;

vector<int> adj[MAXN];
vector<int> visited(MAXN, -1);
bool differentParity = false;

void dfs(int node, int parity) {
    if (visited[node] > 0) {
        if (visited[node] != parity) differentParity = true;
        return;
    }

    visited[node] = parity;

    for (auto a : adj[node]) {
        dfs(a, parity == 1 ? 2 : 1);
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<tuple<ll, ll, ll>> gs(n);
    ll x, y, r;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        gs[i] = make_tuple(x, y, r);
    }

    // preprocess into a traverseable graph
    for (int i = 0; i < n - 1; i++) {
        tuple<ll, ll, ll> g1 = gs[i];
        for (int j = i + 1; j < n; j++) {
            tuple<ll, ll, ll> g2 = gs[j];

            double dist =
                sqrt((get<0>(g2) - get<0>(g1)) * (get<0>(g2) - get<0>(g1)) +
                     (get<1>(g2) - get<1>(g1)) * (get<1>(g2) - get<1>(g1)));

            if (dist == get<2>(g1) + get<2>(g2)) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    // source gear cannot move if for a given path, if reaches it on a dfs
    // traversal of both parities, left and right (-1)
    // source gear can move but it's not connected to the target gear (0)
    dfs(0, 1);

    if (differentParity) {
        cout << -1 << endl;
    } else if (visited[n - 1] < 0) {
        cout << 0 << endl;
    } else {
        ll r1 = get<2>(gs[n - 1]), r2 = get<2>(gs[0]);
        ll d = gcd(r1, r2);
        r1 /= d;
        r2 /= d;

        cout << r1 << " " << (visited[n - 1] == visited[0] ? r2 : -r2) << endl;
    }

    return 0;
}
