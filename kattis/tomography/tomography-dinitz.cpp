#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 2010;

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

            if (level[v] < 0 && res[u][v] > 0) {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }

    return false;
}

bool dfs(int u, int t);

int flow = 0;
bool dfs(int u, int t) {
    if (u == t) {
        while (parent[u] >=
               0) {  // adjust residual graph with the augmenting path
            res[parent[u]][u]--;
            res[u][parent[u]]++;
            u = parent[u];
        }
        flow++;

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

// Can be understood as a network flow problem with a bipartite graph (left are
// rows, right are columns), check for max flow. Solving with dinitz
int main() {
    int m, n;  // rows, columns, n+m vertices + 2 (source and sink) | m rows, n
               // columns
    cin >> m >> n;
    int s = 0, t = m + n + 1;

    // connect source to left side of graph
    for (int i = 0; i < m; i++) {
        adj[s].push_back(i + 1);
        adj[i + 1].push_back(s);
        cin >> res[s][i + 1];
    }

    // connect target to right side of graph
    for (int i = m + 1; i < t; i++) {
        adj[t].push_back(i);
        adj[i].push_back(t);
        cin >> res[i][t];
    }

    // connect rows to columns
    for (int i = 1; i < m + 1; i++) {
        for (int j = m + 1; j < t; j++) {
            adj[i].push_back(j);
            adj[j].push_back(i);
            res[i][j] = 1;
        }
    }

    parent[s] = -1;
    // while we can construct level graph
    while (bfs(s, t, n + m + 2)) {
        while (dfs(s, t))
            ;  // while possible, change residual graph with augmenting paths
        // along the level graph
    }

    for (int i = m + 1; i < t; i++) {
        if (res[i][t] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 1; i < m + 1; i++) {
        if (res[s][i] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
