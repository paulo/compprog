#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 2010;

int res[MAXN][MAXN];
vector<int> adj[MAXN];

vector<int> parent(MAXN, -1);

bool bfs(int s, int t, int n) {
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
            if (res[u][v] > 0 && !visited[v]) {
                Q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t) return true;
            }
        }
    }

    return false;
}

int foldFulkEdKarp(int s, int t, int n) {
    int total = 0;

    while (bfs(s, t, n)) {
        int path_flow = 1;

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

    return total;
}

int main() {
    int n, m;
    cin >> n >> m;

    int s = 0, t = n * 2 + 1;

    // Init capacity and residual
    for (int i = 0; i < n * 2 + 2; i++) {
        for (int j = 0; j < n * 2 + 2; j++) {
            res[i][j] = 0;
        }
    }

    // Link source and sink to edges
    for (int i = 1; i <= n; i++) {
        adj[s].push_back(i);
        adj[i].push_back(s);
        adj[t].push_back(i + n);
        adj[i + n].push_back(t);

        res[s][i] = 1;
        res[i + n][t] = 1;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        adj[a].push_back(b + n);
        adj[b + n].push_back(a);
        adj[b].push_back(a + n);
        adj[a + n].push_back(b);

        // Build residual graph
        res[a][b + n] = 1;
        res[b][a + n] = 1;
    }

    int flow = foldFulkEdKarp(s, t, n * 2 + 2);
    if (flow != n) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (res[j + n][i]) {
                cout << j << endl;
            }
        }
    }

    // cout << flow << endl;

    return 0;
}
