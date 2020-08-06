#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Classic graph coloring problem. Since there are only 4 animals/colors and there's no impossible solution, I'm assuming it's a planar graph
unordered_map<int, int> colors;
const int MAXN = 110;
vector<int> adj[MAXN];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) adj[i] = vector<int>();
    unordered_map<int, unordered_map<int,bool>> m; // check for duplicates
    queue<int> Q;

    int u, v;
    char aux;
    while(cin >> u >> aux >> v) {
        if(v > u) swap(u, v);
        if(m.find(u) != m.end() && m[u].find(v) != m[u].end()) continue;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    Q.push(0);
    colors[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        bool avail[4] = {true, true, true, true};
        for(auto v: adj[u]) {
            if(colors[v] != 0){
                avail[colors[v]-1] = false;
            } else Q.push(v);
        }

        int c=0;
        for(;c < 4; c++) if(avail[c]) break;
        if(c == 4) {
            for(auto v:adj[u]) { // if this combination does not work, let's try another one
                if(colors[v] != 0) {
                    colors[v] = 0;
                    Q.push(v);
                }
            }
        } else colors[u] = c+1;
    }

    for(int i=0; i < n; i++) {
        cout << i + 1 << ' ' << colors[i] << endl;
    }

    return 0;
}
