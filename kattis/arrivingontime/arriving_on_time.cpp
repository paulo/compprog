#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
    pq;

#define pb push_back

const int INF = 2000000000;

// departs from tram stop u
// arrives at tram stop v
// starts its first departure t0 seconds from now
// departs every p seconds from the first departure
// and takes d seconds from departure to arrival
struct bus {
    int u, v, t0, p, d;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<bus>> adj(n);

    bus b;
    for (int i = 0; i < m; i++) {
        cin >> b.u >> b.v >> b.t0 >> b.p >> b.d;

        adj[b.u].pb(b);
    }

    pq q;
    int l = 0, r = s, mid = 0, best = -1;
    while (r >= l) {
        mid = l + (r - l) / 2;

        vi dist(n, INF);
        q.push({mid, 0});
        dist[0] = mid;

        while (!q.empty()) {
            int d = q.top().first, u = q.top().second;
            q.pop();

            if (d > dist[u]) continue;

            for (auto v : adj[u]) {
                // cost of edge is time of travel + time of awaiting
                int c = v.d;
                if (v.t0 >= d) {
                    c += v.t0;
                } else {
                    c += d + (v.p - ((d - v.t0) % v.p)) % v.p;
                }

                if (dist[v.v] > c) {
                    dist[v.v] = c;
                    q.push({c, v.v});
                }
            }
        }

        if (dist[n - 1] <= s) {
            best = max(best, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (best < 0) {
        cout << "impossible" << endl;
    } else {
        cout << best << endl;
    }

    return 0;
}
