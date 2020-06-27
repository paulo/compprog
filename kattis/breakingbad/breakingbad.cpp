#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100100;
vector<int> adj[N];
int side[N];
map<string, int> msi;
map<int, string> mis;
bool is_bipartite = true;

void check_bipartite(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (side[v] == -1) {
            side[v] = 1 - side[u];
            check_bipartite(v);
        } else if (side[u] == side[v]) {
            is_bipartite = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    memset(side, -1, N*sizeof(int));

    string x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        msi[x] = i;
        mis[i] = x;
        adj[i] = vector<int>();
    }

    int m;
    cin >> m;
    string a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[msi[a]].push_back(msi[b]);
        adj[msi[b]].push_back(msi[a]);
    }

    for (int u = 0; u < n; u++) {
        if (side[u] == -1) {
            side[u] = 0;
            check_bipartite(u);
        }
    }

    vector<int> other;
    if(!is_bipartite) cout << "impossible" << endl;
    else {
        for(int i = 0; i < n; i++) {
            if(side[i] == 1) cout << mis[i] << ' ';
            else other.push_back(i);
        }
        cout << endl;

        for(auto o:other) {
            cout << mis[o] << ' ';
        }
        cout << endl;
    }
}
