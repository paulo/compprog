#include <math.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define PI 3.14159265

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

struct ring {
    double x, y, r;
    ring(double _x, double _y, double _r) {
        x = _x;
        y = _y;
        r = _r;
    }

    bool connected(ring r2) {
        double d = sqrt(pow(r2.x - x, 2) + pow(r2.y - y, 2));
        if (r2.r > d + r) {  // inside r2
            return false;
        } else {
            return d < r2.r + r;
        }
    }
};

struct comp {
    bool operator()(const ring& r1, const ring& r2) const {
        double a1 = PI * r1.r * r1.r;
        double a2 = PI * r2.r * r2.r;

        return a1 < a2;
    }
};

int main() {
    int n;
    double x, y, r;

    while (cin >> n && n != -1) {
        vector<ring> rs;
        union_find uf(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            rs.push_back(ring(x, y, r));
        }

        sort(rs.begin(), rs.end(),
             comp());  // order so the check for if a ring is inside another one
                       // is consistent

        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                if (rs[i].connected(rs[j])) {
                    uf.unite(i, j);
                }
            }
        }

        vector<int> mx(n, 0);
        for (int i = 0; i < n; i++) {
            mx[uf.find(i)] += 1;
        }

        int mc = *max_element(begin(mx), end(mx));

        cout << "The largest component contains " << mc;

        if (mc == 1) {
            cout << " ring." << endl;
        } else {
            cout << " rings." << endl;
        }
    }

    return 0;
}
