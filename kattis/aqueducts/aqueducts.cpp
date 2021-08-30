#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
    pq;

#define pb push_back
struct hill {
    int x, y, h;
};

struct edge {
    int u, v;
    ld d;
};

const int MAXN = 510;
const int MAXFLOW = 1 << 30;

int res[MAXN][MAXN];
ld dists[MAXN][MAXN];
vector<edge> adj[MAXN];
vi parent(MAXN, -1);
vector<hill> coords(MAXN);

ld totalDist = 0;

ld dist(hill h1, hill h2) {
    return hypotl(hypotl(h1.x - h2.x, h1.y - h2.y), (h1.h - h2.h));
}

bool bfs(int s, int t, int n) {
    vector<ld> dt(n, MAXFLOW);  // distance
    pq Q;
    Q.push({0, s});
    dt[s] = 0.0;
    parent[s] = -1;
    ld eps = 1e-06L;

    while (!Q.empty()) {
        int u = Q.top().second;
        ll d = Q.top().first;
        Q.pop();

        if (d > dt[u]) continue;

        for (int v = 0; v < adj[u].size(); v++) {
            int xv = adj[u][v].v;
            ld dd = adj[u][v].d;

            if (res[u][xv] > 0 &&
                ((dt[xv] - eps > dt[u] + dd) || (dt[xv] - eps > dt[u] + dd))) {
                dt[xv] = dt[u] + dd;
                Q.push({dt[xv], xv});
                parent[xv] = u;

                if (xv == t) return true;
            }
        }
    }

    return false;
}

int foldFulkEdKarp(int s, int t, int n) {
    int total = 0;

    while (bfs(s, t, n)) {
        int path_flow = MAXFLOW;
        int u = parent[t], v = t;

        while (v != s) {
            path_flow = min(path_flow, res[u][v]);
            v = u;
            u = parent[v];
        }

        u = parent[t];
        v = t;
        while (v != s) {
            totalDist += dists[u][v];

            res[u][v] -= path_flow;
            res[v][u] += path_flow;
            v = u;
            u = parent[v];
        }

        total += path_flow;
    }

    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, t, q;
    cin >> n >> s >> t >> q;

    cout << fixed;
    cout << setprecision(8);

    hill h;
    for (int i = 0; i < n; i++) {
        cin >> h.x >> h.y >> h.h;
        coords[i] = h;
    }

    int source = 0, target = n + 1;
    int aux;
    // connect source to left side of the bipartite graph
    for (int i = 0; i < s; i++) {
        cin >> aux;
        adj[source].push_back({source, aux, 0});
        adj[aux].push_back({aux, source, 0});
        res[source][aux] = 1;
        dists[aux][source] = 0;
    }

    // connect right side of the bipartite graph to target
    for (int i = 0; i < t; i++) {
        cin >> aux;
        adj[aux].push_back({aux, target, 0});
        adj[target].push_back({target, aux, 0});
        res[aux][target] = 1;
        dists[aux][target] = 0;
        dists[target][aux] = 0;
    }

    // connect hills between each other
    ld d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // if (i == j) continue;
            d = dist(coords[i - 1], coords[j - 1]);
            if (d <= q && coords[i - 1].h > coords[j - 1].h) {
                adj[i].push_back({i, j, d});
                adj[j].push_back({j, i, -d});
                res[i][j] = s + t;
                res[j][i] = 0;
                dists[i][j] = d;
                dists[j][i] = -d;
            }
        }
    }

    int flow = foldFulkEdKarp(source, target, n + 2);
    if (flow == t) {
        cout << totalDist << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
