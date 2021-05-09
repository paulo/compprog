#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int MAXN = 100010;
vector<int> adj[MAXN];
vector<bool> visited(MAXN, false);
stack<int> way;
bool found = false;

void topsort(int u, int prev) {
    if (found) return;
    if (visited[u]) {
        vector<int> v;
        v.pb(u);
        while (!way.empty() && way.top() != u) {
            v.pb(way.top());
            way.pop();
        }
        v.pb(u);
        cout << v.size() << endl;
        for (auto x : v) cout << x + 1 << " ";
        cout << endl;
        found = true;
        return;
    }
    visited[u] = true;
    way.push(u);

    for (int i = 0; i < int(adj[u].size()); i++) {
        if (adj[u][i] != prev) topsort(adj[u][i], u);
    }
    way.pop();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) topsort(i, -1);
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
