#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

typedef long double ld;

struct edge {
    int u, v;
    ld weight;
    edge(int _u, int _v, ld _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

vector<ld> dijkstra(int start, int n, vector<vector<edge>> adj) {
    vector<ld> dist(n, 0);

    dist[start] = 1.0;
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> pq;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        ld d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            ld w = adj[u][i].weight;
            if (w * dist[u] > dist[v]) {
                dist[v] = w * dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int n, m, u, v;
    ld f;

    cout << fixed;
    cout << setprecision(4);

    while(cin >> n >> m && !(n == 0 && m == 0)){
        vector<vector<edge>> adj(n, vector<edge>());

        for(int i = 0; i < m; i++){
            cin >> u >> v >> f;

            if(u>v) swap(u,v);

            adj[u].push_back(edge(u, v, f));
            adj[v].push_back(edge(v, u, f));
        }

        vector<ld> dist = dijkstra(0, n, adj);

        cout << dist[n-1] << endl;
    }
}
