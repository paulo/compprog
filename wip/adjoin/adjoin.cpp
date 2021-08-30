#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back

struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x, int y) { parent[find(x)] = find(y); }
};

const int MAXN = 100010;
vector<int> adj[MAXN];
vb visited(MAXN, false);

// It's a tree so we don't have to worry about cycles
int findLeaf(int start, int prev) {
    if ((adj[start].size()) == 1) return start;

    // if (visited[start]) return -1;

    visited[start] = true;
    for (auto a : adj[start]) {
        if (a == prev) continue;

        return findLeaf(a, start);
    }

    return start;
}

int diameter(int start, int prev, int curr) {
    int mx = curr;
    for (auto a : adj[start]) {
        if (a == prev) continue;

        mx = max(mx, diameter(a, start, curr + 1));
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    union_find uf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);

        uf.unite(a, b);
    }

    // TODO: find highest point in each component
    // TODO: join components by highest point


    unordered_map<int, bool> ps;
    vi parents;
    // join disconnected components
    for (int i = 0; i < n; i++) {
        if (ps.find(uf.find(i)) == ps.end()) {
            parents.pb(uf.find(i));
            ps[uf.find(i)] = true;
            cout << uf.find(i) << endl;
        }
    }

    // TODO: This causes cycles
    for (int i = 0; i < int(parents.size()) - 1; i++) {
        for (int j = i + 1; j < int(parents.size()); j++) {
            adj[parents[i]].pb(parents[j]);
            adj[parents[j]].pb(parents[i]);
        }
    }

    int leaf = findLeaf(0, -1);
    cout << diameter(leaf, -1, 0) << endl;

    return 0;
}
