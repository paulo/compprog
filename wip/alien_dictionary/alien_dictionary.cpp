#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // Khan's algorithm:
    // https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
    string alienOrder(vector<string>& words) {
        vector<int> indegrees(26, 0);
        set<int> uniqs;
        vector<vector<int>> adj(26, vector<int>());

        for (int i = 1; i < words.size(); i++) {
            for (char c : words[i - 1]) uniqs.insert(c - 'a');
            for (int j = 0; j < words[i].size() && j < words[i - 1].size();
                 j++) {
                if (words[i][j] == words[i - 1][j]) {
                    if (j == words[i].size() - 1 &&
                        words[i].size() < words[i - 1].size()) {
                        return "";
                    } else {
                        continue;
                    }
                }

                // uniqs.insert(words[i][j] - 'a');
                // uniqs.insert(words[i - 1][j] - 'a');
                adj[words[i - 1][j] - 'a'].push_back(words[i][j] - 'a');
                indegrees[words[i][j] - 'a']++;
                break;
            }
        }
        for (char c : words[words.size() - 1]) uniqs.insert(c - 'a');

        queue<int> q;
        int visited = 0;
        for (auto i : uniqs) {
            // cout << char(i + 'a') << endl;
            if (indegrees[i] == 0) {
                // cout << char(i + 'a') << endl;
                q.push(i);
            } else {
                // cout << char(i + 'a') << " - " << indegrees[i] << endl;
            }
        }

        vector<char> res;
        while (!q.empty()) {
            int top = q.front();
            // cout << char('a' + top) << endl;
            q.pop();
            visited++;
            res.push_back(top + 'a');

            for (int i = 0; i < adj[top].size(); i++) {
                indegrees[adj[top][i]]--;
                if (indegrees[adj[top][i]] == 0) q.push(adj[top][i]);
            }
        }

        return string(res.begin(), res.end());
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    // vector<string> words = {"z", "x", "z"};
    // vector<string> words = {"wrt", "wrtkj"};
    vector<string> words = {"z", "z"};

    cout << Solution().alienOrder(words) << endl;

    return 0;
}
