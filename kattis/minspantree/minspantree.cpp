#include <iostream>
#include <vector>
#include <algorithm>

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

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

bool edge_cmp(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

bool res_cmp(const edge &a, const edge &b) {
    if(a.u == b.u) return a.v < b.v;

    return a.u < b.u;
}

long long cost;

vector<edge> mst(int n, vector<edge> edges) {
    union_find uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            res.push_back(edges[i]);
            cost += edges[i].weight;
        }
    }
    return res;
}

int main() {
    int n, m, u, v, w;

    while(cin >> n >> m && !(n == 0 && m == 0)){
        vector<edge> e;
        cost = 0;
        for (int i = 0; i < m; i++){
            cin >> u >> v >> w;

            if(u > v) swap(u, v);
            e.push_back(edge(u, v, w));
        }

        vector<edge> res = mst(n, e);
        // Amount of edges has to be amount of vertices - 1
        // if it's less, the tree can't span all vertices
        // if it's more, there's a cycle
        if(res.size() != n - 1) {
            cout << "Impossible" << endl;
        } else {
            cout << cost << endl;
            sort(res.begin(), res.end(), res_cmp);
            for(auto e:res) {
                cout << e.u << ' ' << e.v << endl;
            }
        }
    }
}
