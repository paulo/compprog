#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll INF = 10000000000000;

struct edge {
    ll a, b, w;

    edge(ll _a, ll _b, ll _w) {
        a = _a;
        b = _b;
        w = _w;
    }
};

// Trying out Bellman-Ford
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q, s, a, b, w, t;
    while (cin >> n >> m >> q >> s && n != 0) {
        vector<edge> ve;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            ve.push_back(edge(a, b, w));
        }

        vector<ll> distance(n, INF);
        distance[s] = 0;

        // Extra couple of rounds just to check if there's any negative cycle
        for (int i = 0; i <= n + 1; i++) {
            for (auto e : ve) {
                // Avoid computing if distance[e.a] not set yet because it can
                // give incorrect results if the e.w is negative and e.b is also
                // not set
                if (distance[e.a] == INF) continue;

                if (i >= n - 1 && distance[e.b] > distance[e.a] + e.w) {
                    distance[e.b] = -INF;
                } else {
                    distance[e.b] = min(distance[e.b], distance[e.a] + e.w);
                }
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> t;

            if (s == t) {
                cout << 0 << endl;
                continue;
            }

            if (t >= n) {
                cout << "Impossible" << endl;
                continue;
            }

            if (distance[t] == -INF) {
                cout << "-Infinity" << endl;
            } else if (distance[t] == INF) {
                cout << "Impossible" << endl;
            } else {
                cout << distance[t] << endl;
            }
        }
    }

    return 0;
}
