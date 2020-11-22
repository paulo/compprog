#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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

struct edge {
    int u, v;
    int weight;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

bool edge_cmp(const edge &a, const edge &b) { return a.weight < b.weight; }

// Minimum spanning tree that returns the weight of the selected edges
int mst(int n, vector<edge> edges) {
    union_find uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    int res = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            res += edges[i].weight;
        }
    }
    return res;
}

int main() {
    int t, m, c;
    cin >> t;

    int a, b, w, e, total;
    for (int i = 0; i < t; i++) {
        cin >> m >> c;
        e = (c * (c - 1)) / 2;

        vector<edge> edges;
        for (int j = 0; j < e; j++) {
            cin >> a >> b >> w;

            edges.push_back(edge(a, b, w));
        }

        total = mst(c, edges);

        if (total + c > m) {
            cout << "no" << endl;
        } else
            cout << "yes" << endl;
    }

    return 0;
}
