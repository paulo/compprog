#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 100000000;

struct edge {
    int u, v;
    int weight;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

vector<edge> adj[10000];

void dijkstra(int start, int end) {
    vector<int> dist(100, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v, w = adj[u][i].weight;
            if (w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int dcity;
    cin >> dcity;

    int g = 100;
    int d, p;
    vector<pair<int, int>> m;

    while (cin >> d >> p) {
        m.push_back(make_pair(d, p));
    }

    int i = 0;
    while (i < m.size()) {
        for (int j = i + 1; j < m.size() && m[j].first - m[i].first <= 200;
             j++) {
            adj[i].push_back(edge(i, j, m[j].first - m[i].first));
        }

        i++;
    }

    dijkstra(0)

        return 0;
}
