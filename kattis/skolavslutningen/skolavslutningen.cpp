#include <iostream>
#include <set>
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

int main() {
    int n, m, k;
    char aux;
    cin >> n >> m >> k;

    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++) {
        v[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            cin >> aux;
            v[i][j] = aux - 65;
        }
    }
    union_find uf(k);

    // Unite all column collisions
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            uf.unite(v[0][i], v[j][i]);
        }
    }

    set<int> s;

    for (int i = 0; i < k; i++) {
        s.insert(uf.find(i));
    }

    cout << s.size() << endl;

    return 0;
}
