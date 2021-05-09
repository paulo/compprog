#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long int ll;
typedef priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
    pq;

struct edge {
    int u, v;
    ll w;
};

const ll INF = 1000000000000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n, vector<pair<int, ll>>());
    int u, v;
    ll w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;

    pq q;
    vector<bool> visited(n, false);
    q.push({0, 0});

    // adapted dijkstra. I tried bellman_ford and SPFA but both took too long
    // but removing the distance constraint from dijkstra, we can obtain the
    // shortest path for every node
    while (!q.empty()) {
        u = q.top().second;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto v : adj[u]) {
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                q.push({dist[v.first], v.first});
            }
        }
    }

    for (int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}
