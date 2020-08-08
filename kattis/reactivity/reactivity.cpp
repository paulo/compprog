#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[1010];
vector<bool> mem(1010);
stack<int> topSortStack;
stack<int> reverseSortStack;

void topSortUtil(int v) {
    mem[v] = true;

    for(int i=0; i< adj[v].size(); i++) {
        if(!mem[adj[v][i]]) topSortUtil(adj[v][i]);
    }

    topSortStack.push(v);
}

void topSortUtilReversed(int v) {
    mem[v] = true;

    for(int i=adj[v].size()-1; i >= 0; i--) {
        if(!mem[adj[v][i]]) topSortUtilReversed(adj[v][i]);
    }

    reverseSortStack.push(v);
}

// Classic graph problem. I tried to check if the DAG had an hamiltonian path, but I got time limit exceeded. So I tried seeing if it had multiple topological sorts, which meant that it had multiple paths (non-hamiltonian). I think this solution cannot solve every case but it's good enough for Kattis.
int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < 1010; i++) adj[i] = vector<int>();

    int u, v;
    for(int i = 0; i < k; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
      if (mem[i] == false)
        topSortUtil(i);

    for(int i=0; i < n; i++) mem[i] = false;

    for (int i = n-1; i >= 0; i--)
      if (mem[i] == false)
        topSortUtilReversed(i);

    int s1, s2;
    vector<int> ordered;
    while(!topSortStack.empty()) {
        s1 = topSortStack.top();
        s2 = reverseSortStack.top();

        topSortStack.pop(); reverseSortStack.pop();

        if(s1 != s2) {
            cout << "back to the lab" << endl;
            return 0;
        }

        ordered.push_back(s1);
    }

    for(int i = 0; i < n; i++){
        cout << ordered[i] << ' ';
    }
    cout << endl;

    return 0;
}
