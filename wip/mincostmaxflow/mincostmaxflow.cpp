#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
const int MAXN = 260;
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
ll costs[MAXN][MAXN];
vector<int> parent(MAXN, -1);

bool bfs(int s, int t, int n, int m) {
    vector<bool> visited(n, false);
    queue<int> Q;
    Q.push(s);
    parent[s] = -1;

    visited[s] = true;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        for (int v = 0; v < n; v++) {
            if (res[u][v] > 0 && !visited[v]) {
                Q.push(v);
                parent[v] = u;
                visited[v] = true;
                if(v == t) return true;
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

vector<ll> dist(MAXN, MAXFLOW);

ll bellman_ford(int n, int start, int end) {
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].v;
                int w = adj[u][j].weight;
                dist[v] = min(dist[v], w + dist[u]);
            }
        }
    }
}

int main() {
    int n, m, s, t, u, v;
    ll cap, cost;

    cin >> n >> m >> s >> t;

    vector<edge> adj[MAXN];
    for(int i = 0; i<n; i++) for(int j = 0; j < n; j++) res[i][j] = -1;
    for(int i = 0; i<n; i++) for(int j = 0; j < n; j++) costs[i][j] = -1;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> cap >> cost;

        adj[u].push_back(edge(u, v, cap));

        // Build residual graph
        res[u][v] = cap;
        res[v][u] = 0;
        costs[u][v] = cost;
    }

    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            if(res[u][v] != -1 && res[v][u] == -1) res[v][u] = 0;
        }
    }

    ll flow = foldFulkEdKarp(s, t, n, m);

    vector<edge> costNetwork[MAXN];
    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            u = adj[i][j].u, v = adj[i][j].v;
            if(res[u][v] != adj[i][j].cap) { // it's in the residual graph
                costNetwork[u].push_back(edge(u, v, costs[u][v]));
            } else {
                costNetwork[u].push_back(edge(u, v, -costs[u][v]));
            }
        }
    }

    ll totalCost = 0;

    for(int i = 0; i < MAXN; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            if(res[adj[i][j].u][adj[i][j].v] != adj[i][j].cap) {
                totalCost += costs[adj[i][j].u][adj[i][j].v] * (adj[i][j].cap - res[adj[i][j].u][adj[i][j].v]);
            }
        }
    }

    cout << flow << ' ' << totalCost << endl;

    // for(int i = 0; i < vpp.size(); i++) {
        // if(vpp[i].cap == 0) continue;
        // cout << vpp[i].u << ' ' << vpp[i].v << ' ' << vpp[i].cap << endl;
    // }

    return 0;
}
