#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // O(N log k)

        for (auto x : nums) {
            pq.push(x);
            if (pq.size() > k) {
                cout << pq.top() << endl;
                pq.pop();
            }
        }

        return pq.top();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << Solution().findKthLargest(nums, 4) << endl;
    return 0;
}
