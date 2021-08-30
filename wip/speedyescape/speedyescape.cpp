#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back

const int INF = 100000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, e;
    cin >> n >> m >> e;

    int dist[110][110];
    // memset(dist, 0, 110 * 110 * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    int u, v;
    float l;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> l;
        u--;
        v--;
        if (dist[u][v] != INF || dist[v][u] != INF)
            throw std::runtime_error("invalid");
        dist[u][v] = l;
        dist[v][u] = l;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vi es(e);
    int aux;
    for (int i = 0; i < e; i++) {
        cin >> aux;
        es[i] = aux - 1;
    }

    int b, p;
    cin >> b >> p;
    b--;
    p--;

    double best = 100000000000, speed = 0;
    for (auto ex : es) {
        speed = 160.0 * dist[b][ex] / dist[p][ex];
        // cout << dist[b][ex] << endl;
        // cout << dist[p][ex] << endl;
        best = min(best, speed);
    }

    cout << fixed;
    cout << setprecision(10);

    if (best > 160) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << best << endl;
    }

    return 0;
}
