#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define pb push_back

const int MAXN = 10010;

vi adj[MAXN];
vector<bool> visited;

bool dfs(int node) {
    if (visited[node]) return true;

    visited[node] = true;
    for (auto a : adj[node]) {
        if (dfs(a))
            return true;
        else  // if this path does not contain a cycle, we have to clean it up
              // and explore a different path
            visited[a] = false;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cc = 0;
    cin >> n;

    unordered_map<string, int> c2i;

    string s1, s2;
    int c1, c2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;

        if (c2i.find(s1) == c2i.end()) {
            c2i[s1] = cc;
            c1 = cc;
            cc++;
        } else {
            c1 = c2i[s1];
        }

        if (c2i.find(s2) == c2i.end()) {
            c2i[s2] = cc;
            c2 = cc;
            cc++;
        } else {
            c2 = c2i[s2];
        }

        adj[c1].pb(c2);
    }

    string aux;
    // Check for cycles
    while (cin >> aux) {
        cout << aux;

        visited = vector<bool>(cc - 1, false);

        if (dfs(c2i[aux])) {
            cout << " safe" << endl;
        } else {
            cout << " trapped" << endl;
        }
    }

    return 0;
}
