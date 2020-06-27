#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <functional>

using namespace std;

int main() {
    int n_rules;
    string changed;

    cin >> n_rules;
    getline(cin, changed); // Just to get rid of the \n

    map<string,vector<string>> adj;

    // Build graph
    string line, lastdep, currentw;
    for (int i = 0; i < n_rules; i++) {
        getline(cin, line);

        size_t last = 0;
        size_t next = 0;
        while ((next = line.find(' ', last)) != string::npos) {
            lastdep = line.substr(last, next-last);

            if(last == 0) { // First word
                currentw = lastdep.substr(0, lastdep.size()-1);
            } else {
                adj[lastdep].push_back(currentw);
            }

            last = next + 1;
        }

        if(last != 0){
            lastdep = line.substr(last);
            adj[lastdep].push_back(currentw);
        }
    }

    getline(cin, changed);

    map<string, bool> visited;
    stack<string> sorted;

    function<void(string)>dfs = [&] (string w) {
        if(visited[w]) {
            return;
        }
        visited[w] = true;

        vector<string> deps = adj[w];

        for(size_t i=0; i < deps.size(); i++){
            dfs(deps[i]);
        }
        sorted.push(w);
    };

    dfs(changed);
    while(!sorted.empty()) {
        cout << sorted.top() << '\n';
        sorted.pop();
    }

    return 0;
}
