#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100100];
vector<int> side(100100, -1);

// I'm already assuming that the graph can be bipartite since it has 2n-2 edges
void bipartite(int u) {
    for(int i = 0; i < adj[u].size(); i++) {
        if(side[adj[u][i]] == -1) {
            side[adj[u][i]] = 1 - side[u];
            bipartite(adj[u][i]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) adj[i] = vector<int>();

    vector<pair<int, int>> edges(n);
    int a, b;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = make_pair(a,b);
    }

    for (int i=0; i<=n; i++) {
        if(side[i] == -1) {
            side[i] = 0;
            bipartite(i);
        }
    }

    for(int i=0; i<n-1; i++) {
        cout << side[edges[i].first] << endl;
    }

    return 0;
}
