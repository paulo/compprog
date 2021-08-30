#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // According to khan topsort algorithm
    // (https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)
    // a DAG must have an node with in-degree equal to 0 and a node with
    // out-degree equal 0. The course can only be finished if there are no
    // cycles
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        vector<int> indegrees(numCourses, 0);
        set<int> nodes;
        vector<vector<int>> adj(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); i++) {
            indegrees[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            nodes.insert(prerequisites[i][0]);
            nodes.insert(prerequisites[i][1]);
        }

        queue<int> q;
        for (auto n : nodes)
            if (indegrees[n] == 0) q.push(n);

        int v;
        int visited = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();

            visited++;
            for (int i = 0; i < adj[top].size(); i++) {
                v = adj[top][i];
                indegrees[v]--;
                if (indegrees[v] == 0) q.push(v);
            }
        }

        return visited == nodes.size();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> requirements = {{1, 0}, {0, 1}};
    // vector<vector<int>> requirements = {{1, 0}};

    cout << Solution().canFinish(2, requirements) << endl;

    return 0;
}
