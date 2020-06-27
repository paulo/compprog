#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int u, v;
    edge(int _u, int _v) {
        u = _u;
        v = _v;
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

// bool edge_cmp(const edge &a, const edge &b) {
    // return a.weight < b.weight;
// }

vector<edge> mst(int n, vector<edge> edges) {
    union_find uf(n);
    // sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;

        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            res.push_back(edges[i]);
        } else {
            return vector<edge>();
        }
    }

    return res;
}

// Classic graph problem, check for cycles and partitions (aka check for spanning tree)
int main() {
    int n, k;
    cin >> n >> k;

    vector<edge> edges;
    int u, v;
    for(int i = 0; i < k; i++) {
        cin >> u >> v;
        edges.push_back(edge(u, v));
    }

    vector<edge> res = mst(n, edges);
    if(res.size() == 0) {
        cout << "back to the lab" << endl;
    } else {
        vector<int> eres;
        for(auto e:res) {
            eres.push_back(e.u);
            eres.push_back(e.v);
        }

        cout << eres[0] << ' ';
        for(int i = 1; i < eres.size(); i++) {
            if(eres[i] != eres[i-1]) cout << eres[i] << ' ';
        }

        cout << endl;
    }

    return 0;
}
