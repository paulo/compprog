#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define w(n) while (cin >> n)
#define pl(n) cout << n << endl

vector<int> dist(1010, INT_MAX);

void dijk(int start, int n, vector<vector<pair<int, int>>> adj) {
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, from, to, w;
    while (cin >> n >> m && n != 0) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++) {
            cin >> from >> to >> w;

            adj[from - 1].pb(make_pair(to - 1, w));
            adj[to - 1].pb(make_pair(from - 1, w));
        }
    }

    return 0;
}
