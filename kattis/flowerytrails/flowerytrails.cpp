#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
    pq;

#define pb push_back

const int INF = 1000000000;
const int MAXN = 10010;

vector<pair<int, int>> adj[MAXN];
vector<int> pred[MAXN];
unordered_map<int, unordered_map<int, int>> weights;
vector<bool> visited;

int dfs(int t) {
    if (t == 0) return 0;

    if (visited[t]) return 0;
    visited[t] = true;
    int c = 0;
    for (auto a : pred[t]) {
        c += weights[t][a];
        c += dfs(a);
    }

    return c;
}

// Difficult to do with Floyd-Marshall due to duplicate edges
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;

        if (a == b) continue;
        adj[a].pb({b, w});
        adj[b].pb({a, w});

        // make sure we get the weight we'll actually use on the shortest path
        if (weights[a][b] != 0) {
            weights[a][b] = min(weights[a][b], w);
            weights[b][a] = min(weights[b][a], w);
        } else {
            weights[a][b] = w;
            weights[b][a] = w;
        }
    }

    // dijkstra
    vi dist(MAXN, INF);
    dist[0] = 0;
    pq q;
    q.push({0, 0});

    while (!q.empty()) {
        a = q.top().second;
        int d = q.top().first;
        q.pop();

        if (d > dist[a]) continue;

        for (int i = 0; i < int(adj[a].size()); i++) {
            b = adj[a][i].first;
            w = adj[a][i].second;

            // this works because we're ordering the nodes by weight. If this
            // condition applies, it means that we're following a shorter path
            // that is composed of more edges
            if (dist[b] >= dist[a] + w) {
                if (dist[b] > dist[a] + w) {
                    pred[b].clear();
                    dist[b] = dist[a] + w;
                    q.push({dist[b], b});
                }
                pred[b].pb(a);
            }
        }
    }

    visited = vector<bool>(n, false);

    cout << dfs(n - 1) * 2 << endl;
}
