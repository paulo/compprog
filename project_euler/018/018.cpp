#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#include<queue>

using namespace std;

struct edge {
    int u, v;
    int weight;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

const int LEVELS = 100;
const int INF = 100000;

vector<int> dist(1000000, INF);

void dijkstra(int start, int c, vector<edge> adj[c]) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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
    vector<vector<pair<int, int>>> n(LEVELS, vector<pair<int, int>>());

    int aux, c = 0;
    for(int i=0; i<LEVELS; i++) {
        for(int j=0; j<=i; j++) {
            cin >> aux;
            n[i].push_back(make_pair(100 - aux, c++)); // min path with dijkstra
        }
    }

    vector<edge> adj[c];

    // build graph
    for(int i=0; i<LEVELS-1; i++) {
        for(int j=0; j<=i; j++) {
            pair<int, int> v = n[i][j];
            pair<int, int> v1 = n[i+1][j];
            pair<int, int> v2 = n[i+1][j+1];

            adj[v.second].push_back(edge(v.second, v1.second, v1.first));
            adj[v.second].push_back(edge(v.second, v2.second, v2.first));
        }
    }

    dijkstra(0, c, adj);

    int res = INF;
    for(int j=0; j<LEVELS-1; j++) {
        res = min(res, dist[n[LEVELS-1][j].second]);
    }

    res += n[0][0].first; // cost of the top element

    cout << 100 * LEVELS - res << endl;
}
