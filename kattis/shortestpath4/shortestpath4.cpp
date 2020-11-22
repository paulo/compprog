#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> tup;

const ll INF = 1000000000000000000;

struct edge {
    int u, v;
    ll weight;
    edge(int _u, int _v, ll _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

// The intuition for this is that now it's not enough to minimize by distance
// nor minize by hops. We have to minimize by both and so we have to keep track
// of the min distance for each quantity of hops
ll dijkstra(int start, int target, vector<edge> adj[], int k) {
    vector<vector<ll>> dist(
        k + 1,
        vector<ll>(1010,
                   INF));  // keeps track of the current weight at each junction
    dist[1][start] = 0;

    priority_queue<tup, vector<tup>, greater<tup>> pq;
    pq.push(tup(0, 1, start));

    int ans = -1;
    while (!pq.empty()) {
        auto [d, h, u] = pq.top();
        pq.pop();

        if (u == target) {
            ans = d;
            break;
        }

        if (h >= k) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            ll w = adj[u][i].weight;

            if (dist[h + 1][v] > w + dist[h][u]) {
                dist[h + 1][v] = w + dist[h][u];
                pq.push(tup(dist[h + 1][v], h + 1, v));
            }
        }
    }

    return ans;
}

int main() {
    int tc, nv, v, ve, q, s, t, k;
    ll w;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        vector<edge> adj[1010];
        cin >> nv;
        for (int j = 0; j < nv; j++) {
            cin >> ve;

            for (int k = 0; k < ve; k++) {
                cin >> v >> w;
                adj[j].push_back(edge(j, v, w));
            }
        }

        cin >> q;
        for (int j = 0; j < q; j++) {
            cin >> s >> t >> k;
            if (s == t) {
                cout << 0 << endl;
            } else {
                cout << dijkstra(s, t, adj, k) << endl;
            }
        }
        if (i != tc - 1) cout << endl;
    }

    return 0;
}
