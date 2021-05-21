#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < intervals.size(); i++) {
            if (pq.size() == 0) {
                pq.push(intervals[i][1]);
            } else if (pq.top() <= intervals[i][0]) {
                pq.pop();
                pq.push(intervals[i][1]);
            } else {
                pq.push(intervals[i][1]);
            }
        }

        return pq.size();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};

    cout << Solution().minMeetingRooms(intervals) << endl;

    return 0;
}
