#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double d(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

struct edge {
    int u, v;
    double weight;
    edge(int _u, int _v, double _w) {
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
    void unite(int x, int y) { parent[find(x)] = find(y); }
};

bool edge_cmp(const edge &a, const edge &b) { return a.weight < b.weight; }

vector<edge> mst(int n, vector<edge> edges) {
    union_find uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}

int main() {
    int t, n;
    double x, y;
    cin >> t;

    cout << fixed;
    cout << setprecision(2);
    for (int i = 0; i < t; i++) {
        cin >> n;

        vector<pair<double, double>> v(n);
        vector<edge> ve;

        for (int j = 0; j < n; j++) {
            cin >> x >> y;
            v[j] = make_pair(x, y);
        }

        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ve.push_back(edge(
                    j, k, d(v[j].first, v[j].second, v[k].first, v[k].second)));
            }
        }

        vector<edge> res = mst(n, ve);
        double sum = 0;
        for (auto x : res) {
            sum += x.weight;
        }
        cout << sum << endl << endl;
    }

    return 0;
}
