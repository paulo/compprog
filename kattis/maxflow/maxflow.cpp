#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 510;
const ll MAXFLOW = 1<<30;

struct edge {
    int u, v;
    ll cap;
    edge(int _u, int _v, ll _cap) {
        u = _u;
        v = _v;
        cap = _cap;
    }
};

ll res[MAXN][MAXN];
ll initCaps[MAXN][MAXN];
vector<edge> adj[MAXN];
vector<int> parent(MAXN, -1);

bool bfs(int s, int t, int n, int m) {
    vector<bool> visited(n, false);
    queue<int> Q;
    Q.push(s);
    parent[s] = -1;

    visited[s] = true;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for (int v = 0; v < adj[u].size(); v++) {
            int xv = adj[u][v].v;
            if (res[u][xv] > 0 && !visited[xv]) {
                Q.push(xv);
                parent[xv] = u;
                visited[xv] = true;
                if(xv == t) return true;
            }
        }
    }

    return false;
}

ll foldFulkEdKarp(int s, int t, int n, int m) {
    ll total = 0;

    while(bfs(s, t, n, m)) {
        ll path_flow = MAXFLOW;

        int u = parent[t], v = t;

        while(v != s) {
            path_flow = min(path_flow, res[u][v]);
            v = u; u = parent[v];
        }

        u = parent[t]; v = t;
        while(v != s) {
            res[u][v] -= path_flow;
            res[v][u] += path_flow;
            v = u; u = parent[v];
        }

        total += path_flow;
    }

    return total;
}

int main() {
    int n, m, s, t, u, v;
    ll c;

    cin >> n >> m >> s >> t;
    for(int i = 0; i<n; i++) for(int j = 0; j < n; j++) {res[i][j] = 0; initCaps[i][j] = 0;}

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;

        if(res[u][v] == 0 && res[v][u] == 0) {
            adj[u].push_back(edge(u, v, c));
            adj[v].push_back(edge(v, u, 0));
        }
        // Build residual graph
        res[u][v] = c;
        initCaps[u][v] = c;
    }

    ll flow = foldFulkEdKarp(s, t, n, m);

    vector<edge> vpp;
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < MAXN; j++) {
            if(initCaps[i][j] - res[i][j] > 0) vpp.push_back(edge(i, j, initCaps[i][j] - res[i][j]));
        }
    }

    cout << n << ' ' << flow << ' ' << vpp.size() << endl;

    for(int i = 0; i < vpp.size(); i++) {
        if(vpp[i].cap == 0) continue;
        cout << vpp[i].u << ' ' << vpp[i].v << ' ' << vpp[i].cap << endl;
    }

    return 0;
}
