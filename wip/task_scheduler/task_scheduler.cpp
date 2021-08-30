#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (auto c : tasks) m[c]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto c : m) {
            pq.push({0, -c.second});
        }

        int c = 0;
        int i = 0;
        vector<bool> res(10000, false);
        while (!pq.empty()) {
            auto next = pq.top();
            pq.pop();

            while (res[i] || i < next.first) {
                i++;
            }

            cout << i << " - " << next.first << endl;

            res[i] = true;
            c = max(c, i);
            i++;

            if (next.second < -1) {
                pq.push({i + n, next.second + 1});
            }
        }

        return c;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A',
                          'B', 'C', 'D', 'E', 'F', 'G'};
    cout << Solution().leastInterval(tasks, 2) << endl;

    return 0;
}
