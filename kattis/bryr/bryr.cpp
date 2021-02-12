#include <iostream>
#include <queue>

using namespace std;

struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};

const int MAXN = 100010;

vector<edge> adj[MAXN];
vector<int> dist(MAXN, MAXN);

int dijkstra(int start, int n) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>  // smallest element at the top
        pq;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[n];
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (c == 0) {  // double lane
            adj[a].push_back(edge(a, b, 0));
            adj[b].push_back(edge(b, a, 0));
        } else {  // single lane
            adj[a].push_back(edge(a, b, 1));
            adj[b].push_back(edge(b, a, 1));
        }
    }

    // Find shortest path and count only single lanes
    cout << dijkstra(1, n) << endl;

    return 0;
}
