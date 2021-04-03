#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
    pq;

#define pb push_back

struct edge {
    int u, v, w;
};

const int MAXN = 10010, INF = 10000000;

vector<edge> adj[MAXN];
vector<int> previous[MAXN];

void dijkstra(int s, int n) {
    vector<int> dist(n, INF);
    dist[s] = 0;

    pq q;
    q.push({dist[s], s});

    while (!q.empty()) {
        int u = q.top().second, d = q.top().first;
        q.pop();

        if (d > dist[u]) continue;
        for (auto e : adj[u]) {
            if (dist[e.v] >= dist[u] + e.w) {
                if (dist[e.v] > dist[u] + e.w) {
                    previous[e.v] = vector<int>();
                    dist[e.v] = dist[u] + e.w;
                    q.push({dist[e.v], e.v});
                }
                previous[e.v].pb(e.u);
            }
        }
    }
}

int dfs(int s, int t) {
    if (t == s) return 1;

    int count = 0;
    for (auto e : previous[t]) {
        count += dfs(s, e);
    }

    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, e;
    cin >> n >> e;

    edge ed;
    for (int i = 0; i < e; i++) {
        cin >> ed.u >> ed.v >> ed.w;

        adj[ed.u].pb(ed);
    }

    int s, t;
    cin >> s >> t;
    dijkstra(s, n);

    // Find all paths over the shortest paths, from t to s
    cout << dfs(s, t) << endl;

    return 0;
}
