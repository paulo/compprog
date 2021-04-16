#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define pb push_back

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    vi isl(n, 0);
    vi in(n, 0);

    int t, k, s, v;
    for (int i = 0; i < n; i++) {
        cin >> t >> k;

        isl[i] += t;
        for (int j = 0; j < k; j++) {
            cin >> s >> v;

            in[i] += v;
            adj[s - 1].pb({i, v});
        }
    }

    queue<int> q;
    q.push(0);
    int c = 0;
    vector<bool> visited(n, false);
    visited[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        c++;
        for (auto v : adj[u]) {
            if (visited[v.first]) continue;
            in[v.first] -= v.second;
            if (in[v.first] < isl[v.first]) {
                // we're traversing with BFS, so we need to mark as visited
                // before inserting the queue to avoid inserting multiple times
                // the same node
                visited[v.first] = true;
                q.push(v.first);
            }
        }
    }

    cout << n - c << endl;

    return 0;
}
