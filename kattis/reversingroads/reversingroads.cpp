#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXM=100;

vector<int> low(MAXM), num(MAXM, -1);
vector<bool> incomp(MAXM, false);
int curnum = 0;
int conncomps = 0;
vector<int> adj[MAXM];
stack<int> comp;

// Track which reversions create a connected component if needed
// This wouldn't be needed if we represented the graph as a vector of vertice pairs
vector<pair<int, int>> orderedcomps;

void scc(int u);

void scc(int u) {
    incomp[u] = true;
    comp.push(u);
    low[u] = num[u] = curnum++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            scc(v);
            low[u] = min(low[u], low[v]);
        } else if (incomp[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

   if (num[u] == low[u]) {
        conncomps++;
        while (true) {
            int cur = comp.top();
            comp.pop();
            incomp[cur] = false;
            if (cur == u) break;
        }
    }
}

void clear_everyting() {
    fill(num.begin(), num.end(), -1);
    fill(incomp.begin(), incomp.end(), false);
    low.clear();
    while(!comp.empty()) {comp.pop();}
    curnum = 0;
    conncomps = 0;
}

int reverse(int from, int to){
    int aux = adj[from][to];
    adj[from].erase(adj[from].begin()+to);
    adj[aux].push_back(from);
    return aux;
}

void reverse_back(int from, int to, int aux){
    adj[from].insert(adj[from].begin()+to, aux);
    adj[aux].pop_back();
}

// m indicates the number of locations in the proposal
// n indicates the number of roads connecting these locations
int main() {
    int m, n, a, b, aux;

    for(int cases = 1; cin >> m >> n; cases++) {
        int earliestConn = -1;

        // Build adjency list
        for(int j=0; j < n && cin >> a >> b; j++) {
           adj[a].push_back(b);
           orderedcomps.push_back(make_pair(a,b));
        }

        // Analyse minimum number vertice reach (aka low) of each vertice
        for(int i=0; i< m; i++) if (num[i] == -1) scc(i);

        // Check if graph has only one scc
        if(conncomps == 1) {
            cout << "Case " << cases << ": valid" << endl;
            goto Out;
        }

        // Try to reverse the roads one by one till we get a bridge
        for(int i=0; i < m; i++){
            for(int j=0; j < adj[i].size(); j++){
                clear_everyting();

                aux = reverse(i, j);

                // Build scc again
                for(int k=0; k < m; k++) if (num[k] == -1) scc(k);

                reverse_back(i, j, aux);

                if(conncomps == 1) {
                    vector<pair<int,int>>::iterator it = find(orderedcomps.begin(), orderedcomps.end(), make_pair(i, aux));

                    int index = distance(orderedcomps.begin(), it);
                    if(earliestConn == -1 || earliestConn > index) earliestConn = index;
                }
            }
        }

        if(earliestConn != -1) {
           cout << "Case " << cases << ": " << orderedcomps[earliestConn].first << ' ' << orderedcomps[earliestConn].second << endl;
        } else {

           cout << "Case " << cases << ": invalid" << endl;
        }

Out:
        for(int i=0; i<MAXM; i++) adj[i].clear();
        // Cleanup used structs
        clear_everyting();
        orderedcomps.clear();
    }

    return 0;
}
