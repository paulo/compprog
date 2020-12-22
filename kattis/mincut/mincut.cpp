#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXN = 510;
const ll MAXFLOW = 1 << 30;

ll res[MAXN][MAXN];

vector<int> adj[MAXN];
vector<int> parent(MAXN, -1);

vector<int> reacheable(int s, int t, int n) {
    vector<int> reach;
    reach.push_back(s);

    vector<bool> visited(n, false);
    queue<int> Q;
    Q.push(s);

    visited[s] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (res[u][v] > 0 && !visited[v]) {
                Q.push(v);
                visited[v] = true;
                reach.push_back(v);
            }
        }
    }

    return reach;
}

bool bfs(int s, int t, int n, int delta) {
    vector<bool> visited(n, false);
    queue<int> Q;
    Q.push(s);
    parent[s] = -1;

    visited[s] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (res[u][v] >= delta && !visited[v]) {
                Q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t) return true;
            }
        }
    }

    return false;
}

ll foldFulkEdKarp(int s, int t, int n, int delta) {
    ll total = 0;

    while (delta >= 1) {
        while (bfs(s, t, n, delta)) {
            ll path_flow = MAXFLOW;

            int u = parent[t], v = t;

            while (v != s) {
                path_flow = min(path_flow, res[u][v]);
                v = u;
                u = parent[v];
            }

            u = parent[t];
            v = t;
            while (v != s) {
                res[u][v] -= path_flow;
                res[v][u] += path_flow;
                v = u;
                u = parent[v];
            }

            total += path_flow;
        }
        delta = delta / 2;
    }

    return total;
}

int main() {
    int n, m, s, t, u, v;  // n nodes, m edges
    ll c;

    ll maxC = 0;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;

        if (res[u][v] == 0 && res[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Build residual graph (account for duplicate edges)
        res[u][v] += c;
        maxC = max(maxC, res[u][v]);
    }

    // (optimization) find highest power of 2 lower than max capacity
    ll p = (ll)log2(maxC);
    ll delta = (ll)pow(2, p);

    // Get max flow (and updated residual graph)
    foldFulkEdKarp(s, t, n, delta);

    // Let f be a flow with no augmenting paths.
    // Let A = set of nodes reachable from s in residual network Gf.
    // By definition of A: s ∈ A.
    // By definition of flow f: t ∉ A.
    // So, nodes reacheable by s on the residual graph are part of the min-cut

    vector<int> sinkNodes = reacheable(s, t, n);
    cout << sinkNodes.size() << endl;

    for (int i = 0; i < sinkNodes.size(); i++) {
        cout << sinkNodes[i] << endl;
    }

    return 0;
}
