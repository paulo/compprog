#include <iostream>
#include <queue>
#include <vector>

// NOTE: This approach using Ford–Fulkerson fails the time limit constraint
// and obviously can't be improved through capacity scaling as connecting edges
// have C=1

using namespace std;

const int MAXN = 2010;

vector<int> parent(MAXN, -1);

int res[MAXN][MAXN];
vector<int> rows;
vector<int> cols;
vector<int> adj[MAXN];

bool bfs(int s, int t, int n, int m) {
    vector<bool> visited(n + m + 2, false);
    queue<int> Q;
    Q.push(s);
    parent[s] = -1;

    visited[s] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v] && res[u][v] > 0) {
                Q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t) return true;
            }
        }
    }

    return false;
}

int foldFulkEdKarp(int s, int t, int n, int m, int max) {
    int total = 0;

    while (bfs(s, t, n, m)) {
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
        if (max == total) {
            return total;
        }
    }

    return total;
}

// Can be understood as a network flow problem with a bipartite graph (left are
// rows, right are columns), check for max flow
int main() {
    int m, n;  // rows, columns, n+m vertices + 2 (source and sink) | m rows, n
               // columns
    cin >> m >> n;
    int s = 0, t = m + n + 2;

    int aux, maxFlow = 0;
    for (int i = 0; i < m; i++) {
        cin >> aux;
        rows.push_back(aux);
        maxFlow += aux;
    }

    for (int i = 0; i < n; i++) {
        cin >> aux;
        cols.push_back(aux);
    }

    // connect source to left side of graph
    for (int i = 0; i < m; i++) {
        adj[s].push_back(i + 1);
        adj[i + 1].push_back(s);
        res[s][i + 1] = rows[i];
    }

    // connect target to right side of graph
    for (int i = m + 1; i < t; i++) {
        adj[t].push_back(i);
        adj[i].push_back(t);
        res[i][t] = cols[i - m - 1];
    }

    // connect rows to columns
    for (int i = 1; i < m + 1; i++) {
        for (int j = m + 1; j < t; j++) {
            adj[i].push_back(j);
            adj[j].push_back(i);
            res[i][j] = 1;
        }
    }

    int flow = foldFulkEdKarp(s, t, m, n, maxFlow);

    if (flow == maxFlow)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
