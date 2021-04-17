#include <bits/stdc++.h>

using namespace std;

#define pb push_back

struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) { parent[find(x)] = find(y); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    union_find uf(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
    }

    unordered_map<int, bool> mem;
    int last = -1, parent, count = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        parent = uf.find(i);
        if (mem.find(parent) == mem.end()) {
            if (last != -1) {
                res.pb({last + 1, parent + 1});
                count++;
            }
            last = parent;
            mem[parent] = true;
        }
    }

    cout << count << endl;
    for (auto x : res) {
        cout << x.first << ' ' << x.second << endl;
    }

    return 0;
}
