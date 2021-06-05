#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, bool> visited;

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int total = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                visit(isConnected, i);
                total++;
            }
        }

        return total;
    }

    void visit(vector<vector<int>>& isConnected, int k) {
        visited[k] = true;
        for (int i = 0; i < isConnected[k].size(); i++) {
            if (isConnected[k][i] && !visited[i]) visit(isConnected, i);
        }
    }

    Solution() { visited = unordered_map<int, bool>(); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << Solution().findCircleNum(isConnected) << endl;

    return 0;
}
