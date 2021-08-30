#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back

const int MAXN = 200010;

vector<int> adj[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, p, x, l;
    cin >> c >> p >> x >> l;

    vi orig(c, 0);
    vi in(c, 0);

    x--;
    l--;
    int a, b;
    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        a--;
        b--;
        in[a]++;
        in[b]++;
        orig[a]++;
        orig[b]++;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int> q;
    q.push(l);
    vb leaves(c, false);
    leaves[l] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (leaves[v]) continue;

            in[v]--;

            if (in[v] <= orig[v] / 2) {
                q.push(v);
                leaves[v] = true;
            }
        }
    }

    if (leaves[x]) {
        cout << "leave" << endl;
    } else {
        cout << "stay" << endl;
    }

    return 0;
}
