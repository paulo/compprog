#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); i++) {
            indegrees[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for (int i = 0; i < indegrees.size(); i++)
            if (indegrees[i] == 0) q.push(i);

        vector<int> res;
        int v;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            res.push_back(u);
            for (int i = 0; i < adj[u].size(); i++) {
                v = adj[u][i];

                indegrees[v]--;
                if (indegrees[v] == 0) q.push(v);
            }
        }

        if (res.size() == numCourses) return res;
        return vector<int>();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
