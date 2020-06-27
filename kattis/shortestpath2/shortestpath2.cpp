#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 100000000;

// p and w indicating that there is an edge from u to v in the graph which can
// be traversed at time t0+t*p for all nonnegative integers t, and that it takes
// w time units to traverse the edge
struct edge {
    int u, v, t0, p;
    int weight;
    edge(int _u, int _v, int _w, int _t0, int _p) {
        u = _u;
        v = _v;
        weight = _w;
        t0 = _t0;
        p = _p;
    }
};

vector<edge> adj[10100];
vector<int> dist(10100, INF);

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();

        if (d > dist[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v, w = adj[u][i].weight, t0 = adj[u][i].t0, p = adj[u][i].p;

            // remaining time to use the edge
            int rem = dist[u] - t0;
            if(rem <= 0) rem = -rem; // we haven't reached t0 yet but we can wait the difference
            else { // we've surpassed t0
                if(p != 0) { // but maybe we can compensate
                    rem = t0;
                    while(rem < dist[u]) rem += p;
                    rem = rem - dist[u];
                } else continue;
            }

            if (w + rem + dist[u] < dist[v]) {
                dist[v] = w + rem + dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, m, q, s;
    int u, v, t0, p, d;

    while(cin >> n >> m >> q >> s && (n != 0 || m != 0 || q != 0 || s != 0)){
        for(int i = 0; i < 10100; i++) adj[i] = vector<edge>();
        dist = vector<int>(10100, INF);

        for(int i = 0; i < m; i++) {
            cin >> u >> v >> t0 >> p >> d;
            adj[u].push_back(edge(u, v, d, t0, p));
        }

        dijkstra(s);

        int query;
        for(int i=0; i < q; i++){
            cin >> query;
            if(dist[query] == INF) cout << "Impossible" << endl;
            else cout << dist[query] << endl;
        }
        cout << endl;
    }


    return 0;
}
