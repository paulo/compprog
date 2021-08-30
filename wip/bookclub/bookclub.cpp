#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 20010;

int res[MAXN][MAXN];
vector<int> adj[MAXN];
int level[MAXN];
int parent[MAXN];
queue<int> Q;

// Construct level graph with bfs
bool bfs(int s, int t, int n) {
    memset(level, -1, MAXN * sizeof(int));
    Q.push(s);
    level[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (u == t) return true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];

            // cout << u << ' ' << v << endl;
            if (level[v] < 0 && res[u][v]) {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }

    return false;
}

bool dfs(int u, int t);

bool dfs(int u, int t) {
    if (u == t) {
        while (parent[u] >=
               0) {  // adjust residual graph with the augmenting path
            res[parent[u]][u]--;
            res[u][parent[u]]++;
            u = parent[u];
        }

        return true;
    }

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        // if in the level graph and there's still capacity left in the residual
        // graph
        if (level[v] == level[u] + 1 && res[u][v]) {
            parent[v] = u;
            if (dfs(v, t)) return true;
        }
    }
    return false;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    int s = 0, t = 2 * n + 1;

    // connect source to left side of graph
    for (int i = 1; i < n + 1; i++) {
        adj[s].push_back(i);
        adj[i].push_back(s);
        res[s][i] = 1;
    }

    // connect target to right side of graph
    for (int i = n + 1; i < t; i++) {
        adj[t].push_back(i);
        adj[i].push_back(t);
        res[i][t] = 1;
    }

    // connect sides
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a + 1].push_back(n + b + 1);
        adj[n + b + 1].push_back(a + 1);
        res[a + 1][n + b + 1]++;
    }

    parent[s] = -1;
    // while we can construct level graph
    while (bfs(s, t, 2 * n + 1)) {
        // cout << "levels: ";
        // for (int i = 0; i < t + 1; i++) {
        // cout << level[i] << ' ';
        // }
        // cout << endl;
        while (dfs(s, t))
            ;  // while possible, change residual graph with augmenting paths
        // along the level graph
    }

    for (int i = n + 1; i < n * 2 + 1; i++) {
        if (res[i][t] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int i = 1; i < n + 1; i++) {
        if (res[s][i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
