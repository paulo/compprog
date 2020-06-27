#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<std::string, int> msi;
map<int, std::string> mis;
set<int> adj[40];

stack<int> si;
vector<bool> visited(40, false);

bool dfs(int u, int dest);

bool dfs(int u, int dest) {
    if(u == dest) {
        si.push(u);
        return true;
    }

    if (visited[u]) {
        return false;
    }

    visited[u] = true;
    for(auto v : adj[u]) {
        if(dfs(v, dest)) {
            si.push(u);
            return true;
        }
    }
    return false;
}


int main() {
    int n, count = 0, start, dest;
    std::string s, aux, base;
    char delim = ' ';
    getline(cin, s);
    n = stoi(s);

    // Build adjency list
    for(int i=0; i <= n; i++){
        getline(cin, s);

        // split line and build map of stop - vertex
        size_t current, previous = 0;
        current = s.find(' ');
        while (current != string::npos) {
            aux = s.substr(previous, current - previous);

            if(previous == 0) base = aux;
            if(msi.find(aux) == msi.end()) {
                msi[aux] = count++;
                mis[count-1] = aux;
            }

            if(i==n) {
                start = msi[aux];

                previous = current + 1;
                current = s.find(delim, previous);
                aux = s.substr(previous, current - previous);

                if(msi.find(aux) == msi.end()) {
                    msi[aux] = count++;
                    mis[count-1] = aux;
                }

                dest = msi[aux];

                goto Out;
            }

            if(previous != 0) {
                adj[msi[base]].insert(msi[aux]);
                adj[msi[aux]].insert(msi[base]);
            }

            previous = current + 1;
            current = s.find(delim, previous);
        }
        aux = s.substr(previous, current - previous);
        if(msi.find(aux) == msi.end()) {
            msi[aux] = count++;
            mis[count-1] = aux;
        }

        adj[msi[base]].insert(msi[aux]);
        adj[msi[aux]].insert(msi[base]);
    }
    Out:

    // Traverse the graph keeping track of the path
    if(dfs(start, dest)) {
        while (!si.empty()) {
            cout << mis[si.top()] << ' ';
            si.pop();
        }
    } else {
        cout << "no route found" << endl;
    }

    return 0;
}
